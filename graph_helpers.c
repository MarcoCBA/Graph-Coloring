#include "TheOutsider.h"

u32 vget_label(u32 vamount, u32 * arr, u32 vname)
{
  u32 low = 0;
  u32 mid;
  u32 high = vamount-1;
  while(low <= high){
    mid = (low + high) / 2;
    if (vname < arr[mid]){
      high = mid - 1;
    }
    else if (vname > arr[mid]){
      low = mid + 1;
    }
    else{
      return mid;
    }
  }
  return -1;
}

u32 NumeroDeVertices(Grafo g){
  return g->vamount;
}

u32 NumeroDeLados(Grafo g){
  return g->eamount;
}

u32 NumeroDeColores(Grafo g){
  return g->camount;
}

u32 NombreDelVertice(Grafo g, u32 index){
  return g->labels[g->order[index]];
}

u32 ColorDelVertice(Grafo g, u32 index){
  return g->colors[g->order[index]];
}

u32 GradoDelVertice(Grafo g, u32 index){
  return g->weights[g->order[index]];
}

u32 ColorJotaesimoVecino(Grafo g, u32 vindex, u32 nindex){
  return g->colors[g->relations[g->order[vindex]][nindex]];
}

u32 NombreJotaesimoVecino(Grafo g, u32 vindex, u32 nindex){
  return g->labels[g->relations[g->order[vindex]][nindex]];
}

u32 GradoJotaesimoVecino(Grafo g, u32 vindex, u32 nindex){
  return g->weights[g->relations[g->order[vindex]][nindex]];
}
