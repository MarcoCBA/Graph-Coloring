#include "TheOutsider.h"

int Bipartito(Grafo g){

  // Creo queue.
  u32 * queue = calloc(g->vamount, sizeof(u32));
  u32 head, tail;
  init(&head, &tail);

  // Decoloreo el grafo.
  for(u32 i=0;i<g->vamount;i++){
    g->colors[i] = 0;
  }

  // Cantidad de vertices coloreados.
  u32 j = 0;
  u32 conexas = 0;

  // Intento colorear todo el grafo con dos colores.
  while(j<g->vamount){

    // Elijo vertice sin colorear y lo coloreo.
    u32 index = 0;
    for(index=0; index<g->vamount;index++){
      if(g->colors[index]==0){
        g->colors[index] = 1;
        break;
      }
    }

    // Si encuentro un vertice sin colorear incremento la c/CC.
    conexas++;
    j++;

    // Agrego a la queue dicho elemento.
    enqueue(queue, &tail, index);

    // Coloreo con BFS y dos colores la componente conexa correspondiente al
    // vertice en la cabeza de la queue (index).
    while(!empty(head,tail)){
      u32 p = dequeue(queue,&head);
      for(u32 i=0;i<g->weights[p];i++){
        if(g->colors[g->relations[p][i]]==0){
          enqueue(queue,&tail,g->relations[p][i]);
          j++;
          g->colors[g->relations[p][i]] = 3 - g->colors[p];
        }
      }
    }
  }

  // Libero memoria.
  free(queue);

  // Me fijo si el coloreo es propio. Si no lo es devuelvo -CC.
  for(u32 i=0; i<g->vamount;i++){
    for(u32 j=0;j<g->weights[i];j++){
      if(g->colors[g->relations[i][j]] == g->colors[i]){
        // Si no es bipartito, le doy un coloreo propio.
        NotSoGreedy(g,1);
        return (conexas*(-1));
      }
    }
  }

  // Devuelvo CC.
  return conexas;

}
