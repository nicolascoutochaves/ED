#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arvores.h"

Abp* ABP_Init(Abp *node){
    return NULL;
}



Abp* ABP_Insert(Abp *node, char input[], char output[]){

    if(!node){
        count_comp++;
        
        node = calloc(sizeof(Abp), 1);

        int i = 0;
        do {
            if(input[i] == '\n' || input[i] == '\r'){
                input[i] = '\0';
            }
            node->input[i] = tolower(input[i]);
        }
        while(input[i++] && i < STR_MAX-1);

        i = 0;
        do {
            if(output[i] == '\n' || output[i] == '\r'){
                output[i] = '\0';
            }
            node->output[i] = tolower(output[i]);
        }
        while(output[i++] && i < STR_MAX-1);

  
        node->left = NULL;
        node->right = NULL;
        n_nodes++;
    } else{
        count_comp++;
        if(strcmp(input, node->input) < 0){
            count_comp++;
            node->left = ABP_Insert(node->left, input, output);
        } else{
            count_comp++;
            node->right = ABP_Insert(node->right, input, output);
        }
    }
    return node;
}

void ABP_ShowLevels(Abp *node, int n){

    if(!node)
        return;

    for(int i = 0; i <= n; i++) {
        printf("=");
    }

    printf("%s", node->input);
    printf("--->%s<<", node->output);
    /* int i = 0;
    while(node->output[i]){
        printf("  %02x", node->output[i]); //verifica se o output esta correto
        i++;
    } */
    printf("\n");

    ABP_ShowLevels(node->left, n+1);
    ABP_ShowLevels(node->right, n+1);
}

int ABP_GetLevel (Abp *node){
    if(!node)
        return 0;
    else{
        count_comp++;
        int l = ABP_GetLevel(node->left);
        int r = ABP_GetLevel(node->right);
        if(l > r){
            count_comp++;
            return l+1;
        }
        else {
            count_comp++;
            return r+1;
        }
    }
}


int ABP_Search(Abp **root, char **input){
    count_search++;

    if(!*root){
        count_comp++;
        return 0;
    }
    else{
        if(!strcmp(*input, (*root)->input)){
            count_comp++;
            //printf("%s >>>> %s\n", (*root)->input, (*root)->output);
            *input = (*root)->output;
            return 1;
        } else if(strcmp(*input, (*root)->input) < 0){
            count_comp++;
            return ABP_Search(&(*root)->left, input);
        } else {
            count_comp++;
            return ABP_Search(&(*root)->right, input);
        }
    }
}