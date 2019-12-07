#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "time.h"

// Martinelli Marco - markitocab@gmail.com
// Gomez Facundo Agustin - fagugomez1997@gmail.com
// Gutierrez Gonzalo - gutimore@gmail.com

typedef unsigned int u32;

struct GrafoSt {
  u32 camount; // Cantidad de colores en el coloreo.
  u32 ** relations;
  u32 * weights; // Peso del vertice i en weights[i].
  u32 * colors; // Color del vertice i en colors[i].
  u32 * order; // [label1, label2, ... ,labeln].
  u32 * labels; // Tag para cada vertice.
  u32 vamount;
  u32 eamount;
};

typedef struct GrafoSt * Grafo;

// Funciones auxiliares de stdio.
bool clean_stdin(void);
bool eatExtraInput(void);
void graph_dump(Grafo);
void array_dump(u32*,u32);
void bool_array_dump(bool*, u32);

// Funciones de contruccion y destruccion del grafo:
Grafo ConstruccionDelGrafo(void);
void DestruccionDelGrafo(Grafo);

// Funciones de comparacion.
int compare_u32(const void *, const void *);
int WelshPowellCmp(const void *, const void *);
int ColorBloqCmp(const void *, const void *);

// Funciones de extraccion de datos del grafo/vertices.
u32 vget_label(u32, u32*, u32);
u32 NumeroDeVertices(Grafo);
u32 NumeroDeLados(Grafo);
u32 NumeroDeColores(Grafo);
u32 NombreDelVertice(Grafo, u32);
u32 ColorDelVertice(Grafo, u32);
u32 GradoDelVertice(Grafo, u32);
u32 ColorJotaesimoVecino(Grafo, u32, u32);
u32 NombreJotaesimoVecino(Grafo, u32, u32);
u32 GradoJotaesimoVecino(Grafo, u32, u32);

// Funciones de reordenamiento de vertices.
void OrdenWelshPowell(Grafo);
void OrdenNatural(Grafo);
void AleatorizarVertices(Grafo, u32);
void ReordenManteniendoBloqueColores(Grafo, u32);

// Funciones de coloreo de vertices.
u32 NotSoGreedy(Grafo, u32);
int Bipartito(Grafo);

// Funciones de la implementacion de una queue sobre un array.
void init(u32 *head, u32 *tail);
void enqueue(u32 *q,u32 *tail, u32 element);
u32 dequeue(u32 *q,u32 *head);
u32 empty(u32 head,u32 tail);
u32 full(u32 tail,const u32 size);
void display(u32 *q,u32 head,u32 tail);
