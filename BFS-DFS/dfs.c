#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"

void DFS(int matriz[N][N], int vertice, int visitados[]){
    int i, j;
    i = vertice;
    visitados[i] = 1;
    printf("%5d", i);

    for(j = 0; j < N; j++){
        if(matriz[i][j] && !visitados[j]){
           DFS(matriz, j, visitados);
        }
    }
}