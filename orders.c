#include "TheOutsider.h"

void OrdenWelshPowell(Grafo g){
  // Asigno memoria al buffer que contendra los vertices y weights.
  u32 ** joint = calloc(g->vamount, sizeof(u32*));
  for(u32 i=0;i<g->vamount;i++){
    joint[i] = calloc(2,sizeof(u32));
  }

  // Llenado de ambos arrays de datos.
  for(u32 i=0;i<g->vamount;i++){
    joint[i][0] = i;
    joint[i][1] = g->weights[i];
  }

  // Ordenamiento de la nueva estructura.
  qsort(joint,g->vamount,sizeof(joint[0]),WelshPowellCmp);

  // Asignacion del nuevo orden de vertices.
  for(u32 i=0;i<g->vamount;i++){
    g->order[i] = joint[i][0];
  }

  // Libero el buffer temporal.
  for(u32 i=0;i<g->vamount;i++){
    free(joint[i]);
  }
  free(joint);
}

void OrdenNatural(Grafo g){
  // Los labels de los vertices fueron asignados luego de que estos fueran
  // ordenados en orden creciente. Luego el orden natural de los labels es:
  // [0, ... ,g->vamount-1]
  for(u32 i=0;i < g->vamount; i++){
    g->order[i] = i;
  }
}

void AleatorizarVertices(Grafo g, u32 seed){
  // Para que de el mismo resultado con la misma semilla,
  // voy a partir siempre del orden que el grafo tenia en el momento de carga,
  // es decir, el natural.
  OrdenNatural(g);

  // Mi intento de Congruencia Lineal.
  u32 j,k;

  for(u32 i=0;i < g->vamount; i++){
    seed = (seed * 22695477 + 1) % 4294967296;
    j = seed % g->vamount;
    seed = (seed * 22695477 + 1) % 4294967296;
    k = seed % g->vamount;

    u32 temp = g->order[j];
    g->order[j] = g->order[k];
    g->order[k] = temp;
  }
}

void ReordenManteniendoBloqueColores(Grafo g, u32 x){
  // Este array lleva la cuenta de cuantas veces aparece cada color.
  u32 * camounts = calloc(g->camount, sizeof(u32));
  for(u32 i=0;i<g->vamount;i++){
    camounts[g->colors[i]-1]++;
  }

  // Esta estructura son los bloques de colores.
  u32 ** colorblocks = calloc(g->camount,sizeof(u32*));
  for(u32 i=0;i<g->camount;i++){
    colorblocks[i] = calloc(camounts[i],sizeof(u32));
  }

  // Necesito este array para poder llenar la estructura de bloques de colores.
  u32 * vposition = calloc(g->camount, sizeof(u32));

  // Llenado de bloque de colores.
  for(u32 i=0;i<g->vamount;i++){
    colorblocks[g->colors[i]-1][vposition[g->colors[i]-1]] = i;
    vposition[g->colors[i]-1]++;
  }

//----------------------------------------------------------------------------//
  if(x==0){
    // Lleno el nuevo orden recorriendo colorblocks de fin a inicio.
    u32 step = 0;
    for(u32 i=0;i<g->camount;i++){
      for(u32 j=0;j<camounts[g->camount-1-i];j++){
        g->order[step+j] = colorblocks[g->camount-i-1][j];
      }
      step += camounts[g->camount-i-1];
    }
  }
//----------------------------------------------------------------------------//
  else if(x==1){
    // Genero estructura auxiliar para poder ordenar camounts sin perder los
    // indices.
    u32 ** joint = calloc(g->camount, sizeof(u32*));
    for(u32 i=0;i<g->camount;i++){
      joint[i] = calloc(2,sizeof(u32));
    }

    // Llenado de ambos arrays de datos.
    for(u32 i=0;i<g->camount;i++){
      joint[i][0] = i;
      joint[i][1] = camounts[i];
    }

    // Ordeno la estructura.
    qsort(joint,g->camount,sizeof(joint[0]),ColorBloqCmp);

    // Lleno la estructura en base a joint.
    u32 step = 0;
    for(u32 i=0;i<g->camount;i++){
      for(u32 j=0;j<camounts[joint[i][0]];j++){
        g->order[step+j] = colorblocks[joint[i][0]][j];
      }
      step += camounts[joint[i][0]];
    }

    // Libero memoria.
    for(u32 i=0;i<g->camount;i++){
      free(joint[i]);
    }
    free(joint);
  }
//----------------------------------------------------------------------------//
  else if(x>1){
    // Creo un array que contendra el orden de los bloques de colores.
    u32 * corder = calloc(g->camount,sizeof(u32));
    for(u32 i=0;i<g->camount;i++){
      corder[i] = i+1;
    }

    // Randomizo el orden.
    u32 j,k;
    for(u32 i=0;i < g->camount; i++){
      x = (x * 22695477 + 1) % 4294967296;
      j = x % g->camount;
      x = (x * 22695477 + 1) % 4294967296;
      k = x % g->camount;
      u32 temp = corder[j];
      corder[j] = corder[k];
      corder[k] = temp;
    }

    // Lleno el nuevo orden basandome en el orden de corder[].
    u32 step = 0;
    for(u32 i=0;i<g->camount;i++){
      for(u32 j=0;j<camounts[corder[i]-1];j++){
        g->order[step+j] = colorblocks[corder[i]-1][j];
      }
      step += camounts[corder[i]-1];
    }

    // Libero memoria.
    free(corder);
  }
//----------------------------------------------------------------------------//

  // Libero memoria.
  for(u32 i=0;i<g->camount;i++){
    free(colorblocks[i]);
  }
  free(colorblocks);
  free(camounts);
  free(vposition);
}
