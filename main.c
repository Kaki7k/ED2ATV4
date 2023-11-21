//Thiago Henrique Rodrigues Arakaki 2261286
//Gabriel de Souza Muniz 2475430
#include <stdio.h>
#include <limits.h>

#define verdadeiro 1
#define falso 0
typedef int booleano;
#define V 6
#define INF 99999

void imprimirSolucao(int dist[], int n){
    printf("Vértice   Distância da Origem\n");
    for (int i = 0; i < V; i++)
        printf("v%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int grafo[V][V], int origem){
    int dist[V];
    int conjuntoSPT[V];
    for (int i = 0; i < V; i++){
        dist[i] = INF;
        conjuntoSPT[i] = falso;
    }
    dist[origem] = 0;
    for (int contador = 0; contador < V-1; contador++){
        int min = INF, indiceMinimo;
        for (int v = 0; v < V; v++)
            if (!conjuntoSPT[v] && dist[v] <= min)
                min = dist[v], indiceMinimo = v;
        int u = indiceMinimo;
        conjuntoSPT[u] = verdadeiro;
        for (int v = 0; v < V; v++)
            if (!conjuntoSPT[v] && grafo[u][v] && dist[u] != INF && dist[u]+grafo[u][v] < dist[v])
                dist[v] = dist[u] + grafo[u][v];
    }
    imprimirSolucao(dist, V);
}

int main(){
    int graph[V][V] = {{0, 1, 4, 0, 0, 0},
 {1, 0, 4, 2, 7, 0},
 {4, 4, 0, 3, 5, 0},
 {0, 2, 3, 0, 4, 6},
 {0, 7, 5, 4, 0, 7},
 {0, 0, 0, 6, 7, 0}
 };
    dijkstra(grafo, 0);
    return 0;
}
