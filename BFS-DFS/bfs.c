#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"



void BFS(int matriz[N][N], int vertice, int visitados[], TipoFila *fila){
    int i, j;

    fila = insere(fila, vertice);
    visitados[vertice] = 1;

    while (!vazia(fila)){
        i = removeFila(&fila);
        printf("%5d", j);
        
        for(j = 0; j < N; j++){
            if(matriz[i][j] && !visitados[j]){
                fila = insere(fila, j);
                visitados[j] = 1;
            }
        }
    }

}