#include "TheOutsider.h"

bool clean_stdin(){  // Evitar leer salto de linea del input.
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
  return true;
}

bool eatExtraInput(){
  int c;
  while (1)
  {
    c = getchar();
    if (c == '\n') break;
  }
  return true;
}

void graph_dump(Grafo g){
  printf("\n");
  for(u32 i=0;i<g->vamount;i++){
    printf("%u -> ",i);
    for(u32 l=0;l<g->weights[i];l++){
      printf("%u  ",g->relations[i][l]);
    }
    printf("\n");
  }
  printf("\n");
}

void array_dump(u32 * array, u32 alength){
  printf("\n");
  for(u32 i=0; i<alength;i++){
    printf("%u ",array[i]);
  }
  printf("\n");
}

void bool_array_dump(bool * array, u32 alength){
  printf("\n");
  for(u32 i=0; i<alength;i++){
    printf("%d ",array[i]);
  }
  printf("\n");
}
