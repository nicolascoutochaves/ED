#include "caminhamentos.h"
#include <string.h>
#include <locale.h>


int* ClearBuffer(int* buffer, int size) {
    for (int i = 0; i < size; i++) {
        buffer[i] = 0;
    }
    return buffer;
}

int main()
{
  setlocale(LC_ALL, "Portuguese");
  int i,j;
  int grafo[max+1][max+1];
  int *vis = (int*)malloc(sizeof(int)*(max+1));
  int *vcolor = (int*)malloc(sizeof(int)*(max+1));

  if(!vis || !vcolor) {
    puts("Erro de alocacao de memoria");
    exit(1);
  }


  //para inicializar o gr�fo com 0
  for(i=1;i<=max;i++)
    for(j=1;j<=max;j++)
      grafo[i][j]=0;

    //inicializando o vetor de visitados
    vis = ClearBuffer(vis, max+1);
    vcolor = ClearBuffer(vcolor, max+1);

    
    grafo[1][2]=1;
    grafo[2][1]=1;
    grafo[1][6]=1;
    grafo[6][1]=1;
    grafo[2][3]=1;
    grafo[3][2]=1;
    grafo[2][4]=1;
    grafo[4][2]=1;
    grafo[3][4]=1;
    grafo[4][3]=1;
    grafo[3][5]=1;
    grafo[5][3]=1;
    grafo[4][5]=1;
    grafo[5][4]=1;
    grafo[4][6]=1;
    grafo[6][4]=1;
    grafo[6][5]=1;
    grafo[5][6]=1;

    i=1;
    puts("DFS");
    DFS(grafo,i, vis, vcolor);

    vis = ClearBuffer(vis, max+1);
    vcolor = ClearBuffer(vcolor, max+1);
    puts("\n\nBFS");
    i=1;
    BFS(grafo,i, vis, vcolor);




}
