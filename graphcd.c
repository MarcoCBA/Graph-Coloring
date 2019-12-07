#include "TheOutsider.h"

Grafo ConstruccionDelGrafo(void){
  u32 vam,eam,e1,e2;

  // Obtengo la cantidad de vertices y lados.
  while((scanf("p edge %u %u", &vam, &eam) != 2) && eatExtraInput());

  // Buffers de lados, valencias, y labels.
  u32** edges = calloc(2*eam, sizeof(u32*));
  u32 *weights = calloc(vam, sizeof(u32));
  u32 *labels = calloc(vam, sizeof(u32));
  for(u32 i = 0; i < 2*eam; i++){
    edges[i] = calloc(2, sizeof(u32));
  }

  // Cargo todos los lados dos veces, invirtiendo el orden la segunda vez.
  u32 j = 0;
  for (u32 i=0;i<eam;i++){
    while((scanf("e %u %u", &e1, &e2) != 2) && clean_stdin());
    edges[j][0] = e1;
    edges[j][1] = e2;
    edges[j+1][0] = e2;
    edges[j+1][1] = e1;
    j = j+2;
  }

  // Ordeno los lados en orden creciente.
  qsort(edges,2*eam,sizeof(edges[0]), compare_u32);

  // Llenado de weights y labels.
  labels[0] = edges[0][0];
  weights[0] = 1;
  u32 k = 0;
  for (u32 i=1;i<2*eam;i++){
    if(labels[k] == edges[i][0]){
      weights[k]++;
    }
    else{
      k++;
      labels[k] = edges[i][0];
      weights[k]++;
    }
  }

  // LLenado de la estructura.
  Grafo g = calloc(1,sizeof(struct GrafoSt));
  g->weights = weights;
  g->labels = labels;
  g->vamount = vam;
  g->eamount = eam;
  g->relations = calloc(vam,sizeof(u32*));
  for(u32 i=0;i<vam;i++){
    g->relations[i] = calloc(g->weights[i],sizeof(u32));
  }
  k = 0;
  for(u32 i=0;i<vam;i++){
    for(u32 l=0;l<g->weights[i];l++){
      g->relations[i][l] = vget_label(g->vamount,g->labels,edges[k+l][1]);
    }
    k = k + g->weights[i];
  }

  // El orden inicial es el creciente.
  // Coloreo propio del grafo (los colores empiezan en 1).
  g->order = calloc(vam,sizeof(u32));
  g->colors = calloc(vam,sizeof(u32));
  for(u32 i=0;i<g->vamount;i++){
    g->order[i] = i;
    g->colors[i] = i+1;
  }

  // La cantidad de colores en este caso es una por cada vertice.
  g->camount = g->vamount;

  // Libero memoria.
  for(u32 i = 0; i < 2*eam; i++){
    free(edges[i]);
  }
  free(edges);

  // Retorno el puntero al grafo.
  return g;
}

void DestruccionDelGrafo(Grafo g){

  // Libero arrays de datos.
  free(g->labels);
  free(g->colors);
  free(g->weights);
  free(g->order);

  // Libero lista de adyacencia.
  for(u32 i=0;i<g->vamount;i++){
    free(g->relations[i]);
  }
  free(g->relations);

  // Libero la raiz de la estructura.
  free(g);
}
