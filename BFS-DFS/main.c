#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"


void Clear(int v[]){
    for(int i = 0; i < N; i++){
        v[i] = 0;
    }
}
int main(){
    int matriz[N][N] = {
        {0,1,1,0,0,0,0,0},
        {0,0,0,1,0,0,0,0},
        {0,0,0,1,1,0,0,0},
        {0,0,0,0,1,1,0,1},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0}
        };
    int visitados[N] = {0};

    

    DFS(matriz, 0, visitados);
    printf("\n");
    Clear(visitados);

    DFS(matriz, 2, visitados);
    printf("\n");
    Clear(visitados);

    DFS(matriz, 4, visitados);
    printf("\n");
    Clear(visitados);


    TipoFila *fila = cria_fila();

    BFS(matriz, 0, visitados, fila);
    printf("\n");
    Clear(visitados);

    BFS(matriz, 2, visitados, fila);
    printf("\n");
    Clear(visitados);



    return 0;
}
