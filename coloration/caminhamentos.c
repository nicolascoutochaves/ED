#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "caminhamentos.h"


void Colorize(int graph[max+1][max+1], int v,  int vcolor[max+1]) { //Funcao que colore um vertice baseado nas cores dos vertices adjacentes, sem repetir cores
    int cores_usadas[4] = {0};
    for(int w = 1; w<=max ; w++) {    //percorre os v�rtices adjacentes a v
        if ((graph[v][w]) ){ //encontra um v�rtice adjacente a v
            if(vcolor[w]){
                cores_usadas[(vcolor[w])] = 1;
            }
        }
    } 
    for(int i = 0; i < 4; i++){
        if(!cores_usadas[i]){
            vcolor[v] = i;
        }
    }
     switch (vcolor[v]) {
        case GREEN:
            printf("Verde\n");
            break;
        case RED:
            printf("Vermelho\n");
            break;
        case BLUE:
            printf("Azul\n");
            break;
        case YELLOW:
            printf("Amarelo\n");
            break;
    }
}

void DFS (int grafo[max+1][max+1], int v, int vis[max+1], int vcolor[max+1])
{
    srand(time(NULL));
    int w, i;

    printf("%d ",v);
    Colorize(grafo, v, vcolor);
    vis[v]= true;


    for(w = 1; w<=max ; w++)    //percorre os v�rtices adjacentes a v
        if ((grafo[v][w]== 1) && (vis[w]==false)){ //encontra um v�rtice adjacente a v que ainda nao tenha sido visitado
            

            DFS(grafo, w, vis, vcolor); //chamada recursiva para o v�rtice adjacente a v
      }
}



void BFS (int grafo[max+1][max+1], int v, int vis[max+1], int vcolor[max+1])
{
    int w;
    TipoFila *FV;

    FV = cria_fila();
    FV = insere(FV,v);
    vis[v]= true;
    while (!vazia(FV))
    {
       v = removeFila(&FV);
       printf("%d ",v);
       Colorize(grafo, v, vcolor);
       for(w = 1; w<=max ; w++)    //percorre os v�rtices adjacentes a v
          if ((grafo[v][w]== 1) && (vis[w]==false))  //encontra um v�rtice adjacente a v que ainda nao tenha sido visitado
          {
              FV = insere(FV,w);
              vis[w]= true;
           }

    }
}

