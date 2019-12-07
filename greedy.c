#include "TheOutsider.h"

u32 NotSoGreedy(Grafo g,u32 seed){
  // Los vertices se colorean con 0 para indicar que no estan coloreados.
  for(u32 i=0;i<g->vamount;i++){
    g->colors[i] = 0;
  }

  // El primer vertice del orden se colorea con 1.
  g->colors[g->order[0]] = 1;
  g->camount = 1;

  // Este array va a mantener una referencia por cada vertice, indicando cuales
  // colores estan ocupados o libres por los vecinos.
  // La inicializacion en 0 indica que todos los colores estan libres.
  u32 * ncolors = NULL;
  while(ncolors == NULL){
    ncolors = calloc(g->vamount,sizeof(u32));
  }

  // Coloreo del resto de los vertices.
  for(u32 i=1;i<g->vamount;i++){

    // Necesito saber de cuantos colores disponibles puedo elegir al azar.
    // Se inicializa en la maxima cantidad de colores disponibles, que luego se
    // iran restando.
    u32 modulus = g->camount;

    // Marco los colores de los vecinos del vertice (i) como ocupados
    // en la pos. (i-1) de ncolors, ya que el 1 es el primer color, y no 0.
    // Cada vez que encuentro un color ocupado NUEVO, resto uno a modulus.
    for(u32 j=0;j<g->weights[g->order[i]];j++){
      if(g->colors[g->relations[g->order[i]][j]]){
        if(ncolors[g->colors[g->relations[g->order[i]][j]]-1] == 0){
          modulus--;
          ncolors[g->colors[g->relations[g->order[i]][j]]-1] = 1;
        }
      }
    }


    // Obtengo numero de color a utilizar en base a seed y modulus.
    // Si modulus es 0 porque todos los colores estan ocupados, rc se pone
    // en 0. Esto hace que se elija el primer color disponible,
    // el cual sera uno nuevo.
    // Si modulus es 1, significa que tengo un solo color disponible, lo elijo
    // seteando rc a 0.
    seed = (seed * 22695477 + 1) % 4294967296;
    u32 rc;
    if((modulus==0) || (modulus==1)){
      rc = 0;
    }
    else{
      rc = seed % modulus;
    }

    // Busco el rc color disponible.
    u32 cf = 0;
    for(cf=0;cf<g->camount;cf++){
      if(!ncolors[cf]){
        if(rc==0){
          break;
        }
        rc--;
      }
    }

    // Asigno el color al vertice i en el orden.
    g->colors[g->order[i]] = cf + 1;

    // Incremento la cantidad de colores usados, si es que se uso uno nuevo.
    if(g->camount < cf + 1){
      g->camount++;
    }

    // Vuelvo a 0s el array de colores de los vecinos.
    // Solo tengo que limpiar hasta el maximo color usado.
    // Este es el cuello de botella mas grande. Si recorriera el arreglo por
    // completo, el tiempo de un solo greedy se vuelve catastrofico.
    for(u32 l=0;l<g->camount;l++){
      ncolors[l] = 0;
    }
  }

  // Libero memoria usada.
  free(ncolors);

  // Devuelvo el numero de colores obtenidos.
  return g->camount;
}
