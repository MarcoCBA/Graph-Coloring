#include "TheOutsider.h"

int compare_u32(const void *p, const void *q){
    u32 *x = *(u32**)p;
    u32 *y = *(u32**)q;
    if (x[0] < y[0]){
      return -1;
    }
    else if (x[0] > y[0]){
      return 1;
    }
    else{
      if (x[1] < y[1]){
        return -1;
      }
      else{
        return 1;
      }
    }
    return 0;
}

int WelshPowellCmp(const void *p, const void *q){
  u32 *x = *(u32**)p;
  u32 *y = *(u32**)q;
  if(x[1] > y[1]){
    return -1;
  }
  else if(x[1] < y[1]){
    return 1;
  }
  return 0;
}

int ColorBloqCmp(const void *p, const void *q){
  u32 *x = *(u32**)p;
  u32 *y = *(u32**)q;
  if(x[1] > y[1]){
    return 1;
  }
  else if(x[1] < y[1]){
    return -1;
  }
  return 0;
}
