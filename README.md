## Planteamiento de la estructura:

Para representar el grafo se eligió una estructura sencilla, compuesta de arreglos
y matrices independientes, orientada a favorecer la velocidad de ejecución del
algoritmo principal de este proyecto NotSoGreedy.

![alt_text](https://k62.kn3.net/B1A085A36.png)

La estructura esta compuesta por ocho campos:

- `vamount`: Indica la cantidad de vértices que componen el grafo.
- `eamount`: Indica la cantidad de aristas que componen el grafo.
- `camount`: Indica el número de colores asignado hasta el momento.
- `order`: Este arreglo permite expresar multiples ordenes de los vertices de forma sencillla
si el vertice llamado i ocupa la posición j en el orden esto se expresa como order[j] = Vi.
- `weights`: Este arreglo contiene las valencias de cada vertice.
- `labels`: Este arreglo contiene las etiquetas asignadas a los vertices, elegimos el intervalo [1..n]
- `colors`: Este arreglo contiene los colores asignadas a los vertices, elegimos el intervalo [1..n], 0 significa no coloreado.
- `relations`: Es una matriz de adyacencia que no desperdicia memoria, ya que cada fila es una arreglo independiente de longitud igual a la valencia del vertice al que corresponde.


Para cargar el grafo se utilizo la estructura auxiliar edges, una matriz de dos
columnas y con un número de filas igual al doble de aristas del Grafo.

Escencialmente es una tabla Dimacs con la información duplicada, por cada arista
i-j, se agregan los vertices i y j, y en la fila siguiente j e i.

Al finalizar la carga se ordena edges utilizando qsort y el comparador compare_u32
 definido para tal fin.

 ## NotSoGreedy

En su mayor parte es semejante al algoritmo voraz de coloreo estandar, es decir
se le asigna el primer color disponible al primer vertice en el orden, luego se
recorre cada uno de los restantes vertices en el orden establecido, y por cada uno
de ellos se determina los colores en uso por sus vecinos y se selecciona uno
disponible.

La diferencia radica en la forma en que se elige este color, para ello se lleva
una cuenta de los colores libres, se elige un numero al azar utilizando nuestra
propia función pseudo aleatoria, y de este número se toma el resto de dividirlo
por la cantidad de colores libres.

Finalmente se revisa linealmente el arreglo de colores en uso, cada vez que se
encuentra uno libre, se decrementa esta cantidad, cuando esta llega a cero, se
deduce que ese es el color que debe asignarse.

 ## Bipartito

 En esta función se utiliza una cola como estructura auxiliar fundamental, la
 cual fue implementada en queue.c, ella ayuda al recorrido BFS del grafo durante
 el proceso de coloreo de cada componente conexa.
