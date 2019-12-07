#include "TheOutsider.h"

int main(void){
  // Contadores.
  clock_t start,end;
  double cpu_time_used;

  // Creacion del grafo.
  start = clock();
  Grafo g = ConstruccionDelGrafo();
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Tiempo de carga de grafo: %f\n", cpu_time_used);

  // Ver si el grafo se armo correctamente.
  //graph_dump(g);

  // Test de los ordenes del grafo.
  //printf("El orden incial es:");
  //array_dump(g->order, g->vamount);
  //NotSoGreedy(g,1);
  //printf("El coloreo despues de greedy es:");
  //array_dump(g->colors,g->vamount);

  //ReordenManteniendoBloqueColores(g,1);
  //printf("El ReordenManteniendoBloqueColores (x=1) es:");
  //array_dump(g->order, g->vamount);

  // ReordenManteniendoBloqueColores(g,1)
  //printf("El ReordenManteniendoBloqueColores (x=1) es:");
  //ReordenManteniendoBloqueColores(g,1);
  //array_dump(g->order, g->vamount);

  // OrdenNatural(g);
  //OrdenNatural(g);
  //printf("El orden natural es:");
  //array_dump(g->order, g->vamount);

  // OrdenWelshPowell().
  //OrdenWelshPowell(g);
  //printf("El orden Welsh Powell es:");
  //array_dump(g->order, g->vamount);

  // AleatorizarVertices().
  //AleatorizarVertices(g,11);
  //printf("El orden aleatorio es:");
  //array_dump(g->order, g->vamount);

  // Ver el coloreo incial (de ConstruccionDelGrafo).
  //printf("El coloreo actual es:");
  //array_dump(g->colors, g->vamount);

  // Test de las funciones de extraccion de datos.
  //u32 v = 4;
  //u32 w = 2;
  //printf("El numero de vertices es: %u\n",NumeroDeVertices(g));
  //printf("El numero de lados es: %u\n",NumeroDeLados(g));
  //printf("El numero de colores es: %u\n",NumeroDeColores(g));
  //printf("El nombre del vertice %u en el orden es: %u\n",v,NombreDelVertice(g,4));
  //printf("El color del vertice %u en el orden es: %u\n",v,ColorDelVertice(g,4));
  //printf("El grado del vertice %u en el orden es: %u\n",v,GradoDelVertice(g,4));
  //printf("El grado del vecino %u del vertice %u en el orden es: %u\n",w,v,GradoJotaesimoVecino(g,v,w));
  //printf("El nombre del vecino %u del vertice %u en el orden es: %u\n",w,v,NombreJotaesimoVecino(g,v,w));
  //printf("El color del vecino %u del vertice %u en el orden es: %u\n",w,v,ColorJotaesimoVecino(g,v,w));

  // Test de Greedy.
  u32 greedyam;
  start = clock();
  for(greedyam=0;greedyam<100;greedyam++){
    //OrdenWelshPowell(g);
    //printf("X(G) ~ %u\n",NotSoGreedy(g,21));
    //OrdenNatural(g);
    //printf("X(G) ~ %u\n",NotSoGreedy(g,greedyam));
    //AleatorizarVertices(g,greedyam);
    //printf("X(G) ~ %u\n",NotSoGreedy(g,greedyam));
    ReordenManteniendoBloqueColores(g,0);
    //printf("X(G) ~ %u\n",NotSoGreedy(g,greedyam));
    //ReordenManteniendoBloqueColores(g,greedyam);
    //printf("X(G) ~ %u\n",NotSoGreedy(g,greedyam));
  }
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Tiempo de %u NotSoGreedy(): %fs\n", greedyam, cpu_time_used);

  //printf("El coloreo luego de correr Greedy es:");
  //array_dump(g->colors, g->vamount);

  // Test Bipartito().
  //printf("%d\n", Bipartito(g));
  //array_dump(g->colors,g->vamount);

  // Liberacion de memoria.
  DestruccionDelGrafo(g);

  return 0;
}
