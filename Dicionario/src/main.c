#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>
#include "arvores.h"

int count_comp;
int count_search;
int n_nodes;
int altura;
int n_rotacoes;

FILE *dicionario = NULL, *entrada = NULL, *saida = NULL;

Abp* ABP_Switch(Abp *a){
    char *word, line[1000], *in, *out;
    int flag = 0; //flag para alternar entre as palavras de entrada e saida
    // Lê o arquivo linha por linha

    while (fgets(line, sizeof(line), dicionario))
    {
        // Divide a linha em palavras
        
            word = strtok(line, " \t\n,");
        while (word != NULL) {
            // Insere a palavra na árvore AVL
            if(!flag){
                in = word;
            } else if(flag) {
                out = word;

                if(in != NULL && out != NULL){
                    a = ABP_Insert(a, in, out);
                }
            }

            // Obtém a próxima palavra
            word = strtok(NULL, "\n,");
            flag = !flag;   
        }
    }

    // Lê o arquivo linha por linha
    while (fgets(line, sizeof(line), entrada))
    {
        // Divide a linha em palavras
        word = strtok(line, " \t\n,");
        while (word != NULL) {
            int i = 0;
            while(word[i]){
                word[i] = tolower(word[i]);
                i++;
            }
            // Busca a palavra na árvore AVL
            ABP_Search(&a, &word);
            // Escreve a palavra no arquivo de saída
            fprintf(saida, "%s ", word);
            // Obtém a próxima palavra
            word = strtok(NULL, " \t\n,");
        }
    }
    altura = ABP_GetLevel(a);
    return a;
}

Avl* AVL_Switch(Avl *a){
    char *word, line[1000], *in, *out;
    int flag = 0; //flag para alternar entre as palavras de entrada e saida
    // Lê o arquivo linha por linha

    while (fgets(line, sizeof(line), dicionario))
    {
        // Divide a linha em palavras
        word = strtok(line, " \t\n,");
        while (word != NULL) {
            // Insere a palavra na árvore AVL
            if(!flag){
                in = word;
            } else if(flag) {
                out = word;

                if(in != NULL && out != NULL){
                    a = A_Insert(a, in, out);
                }
            }

            // Obtém a próxima palavra
            word = strtok(NULL, "\n,");
            flag = !flag;   
        }
    }

    // Lê o arquivo linha por linha
    while (fgets(line, sizeof(line), entrada))
    {
        // Divide a linha em palavras
        word = strtok(line, " \t\n,");
        while (word != NULL) {
            int i = 0;
            while(word[i]){
                word[i] = tolower(word[i]);
                i++;
            }
            // Busca a palavra na árvore AVL
            A_Search(&a, &word);
            // Escreve a palavra no arquivo de saída
            fprintf(saida, "%s ", word);
            // Obtém a próxima palavra
            word = strtok(NULL, " \t\n,");
        }
    }
    altura = GetLevel(a);
    return a;

}

Splay* SPLAY_Switch(Splay *a){
    char *word, line[1000], *in, *out;
    int flag = 0; //flag para alternar entre as palavras de entrada e saida
    // Lê o arquivo linha por linha

    while (fgets(line, sizeof(line), dicionario))
    {
        // Divide a linha em palavras
        word = strtok(line, " \t\n,");
        while (word != NULL) {
            // Insere a palavra na árvore AVL
            if(!flag){
                in = word;
            } else if(flag) {
                out = word;

                if(in != NULL && out != NULL){
                    a = S_Insert(a, in, out);
                }
            }

            // Obtém a próxima palavra
            word = strtok(NULL, "\n,");
            flag = !flag;   
        }
    }

    // Lê o arquivo linha por linha
    while (fgets(line, sizeof(line), entrada))
    {
        // Divide a linha em palavras
        word = strtok(line, " \t\n,");
        while (word != NULL) {
            int i = 0;
            while(word[i]){
                word[i] = tolower(word[i]);
                i++;
            }
            // Busca a palavra na árvore AVL
            S_Search(&a, &word);
            // Escreve a palavra no arquivo de saída
            fprintf(saida, "%s ", word);
            // Obtém a próxima palavra
            word = strtok(NULL, " \t\n,");
        }
    }
    altura = Splay_GetLevel(a);
    return a;
}


void OpenFiles(char *argv[]){
    if(!(dicionario = fopen(argv[1], "r"))){
        printf("Erro ao abrir o arquivo %s", *argv[1]);
        exit(1);
    }
    if(!(entrada = fopen(argv[2], "r"))){
        printf("Erro ao abrir o arquivo %s", *argv[2]);
        exit(1);
    }
    if(!(saida = fopen(argv[3], "w"))){
        printf("Erro ao abrir o arquivo %s", *argv[3]);
        exit(1);
    }
   
}

void PrintStats(clock_t start, clock_t end, char string[]){
    FILE *stats = fopen("stats.txt", "a"); //arquivo para salvar as estatisticas
    //ABP_ShowLevels(a,0);
    //A_ShowLevels(b,0);
    //S_ShowLevels(c,0);
    if(stats){
        fprintf(stats, "==========================================\n");
        fprintf(stats, "Arvore: %s\n", string);
        fprintf(stats, "Numero de nos: %d\n", n_nodes);
        fprintf(stats, "Altura da arvore: %d\n", altura);
        fprintf(stats, "Numero de comparacoes: %d\n", count_comp);
        fprintf(stats, "Numero de comparacoes na busca: %d\n", count_search);
        fprintf(stats, "Numero de rotacoes: %d\n", n_rotacoes);
        fprintf(stats, "Tempo decorrido: %f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);
        fclose(stats);
    }
    printf("Numero de nos: %d\n", n_nodes);
    printf("Altura da arvore: %d\n", altura);
    printf("Numero de comparacoes: %d\n", count_comp);
    printf("Numero de comparacoes na busca: %d\n", count_search);
    printf("Numero de rotacoes: %d\n", n_rotacoes);
    printf("Tempo decorrido: %f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);
    puts("\n");
}

void ResetCounters(){
    count_comp = 0;
    count_search = 0;
    n_nodes = 0;
    altura = 0;
    n_rotacoes = 0;
}

void CloseFiles(){
    fclose(dicionario);
    fclose(entrada);
    fclose(saida);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    
    Abp *a = ABP_Init(a);
    Avl *b = A_Init(b);
    Splay *c = S_Init(c);
    clock_t start, end;


    if (argc != 4) { //nome do programa, diciionario, entrada, saida
        printf("Numero incorreto de parametros.\nPara chamar o programa digite: exemplo <dicionario> <arq_entrada> <arq_saida>\n");
        exit(1);
    }
    

    ResetCounters();
    OpenFiles(argv);
    start = clock(); //inicia a contagem do tempo
    a = ABP_Switch(a);
    end = clock(); //finaliza a contagem do tempo
    puts("=============================================");
    puts("\tABP");
    PrintStats(start, end, "ABP");
    CloseFiles();

    ResetCounters();
    OpenFiles(argv);
    start = clock(); //inicia a contagem do tempo
    b = AVL_Switch(b);
    end = clock(); //finaliza a contagem do tempo
    puts("=============================================");
    puts("\tAVL");
    PrintStats(start, end, "AVL");
    CloseFiles();

    ResetCounters();
    OpenFiles(argv);
    start = clock(); //inicia a contagem do tempo
    c = SPLAY_Switch(c);
    end = clock(); //finaliza a contagem do tempo
    puts("=============================================");
    puts("\tSPLAY");
    PrintStats(start, end, "SPLAY");
    CloseFiles();

    free(a);
    free(b);
    free(c);

    a = NULL;
    b = NULL;
    c = NULL;

   return 0;
}
