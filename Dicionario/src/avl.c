#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arvores.h"

Avl* A_Init(Avl *node){
    return NULL;
}



Avl* A_Insert(Avl *node, char input[], char output[]){

    if(!node){
        count_comp++;
        
        node = calloc(sizeof(Avl), 1);

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

  


        node->bf = 0;
        node->left = NULL;
        node->right = NULL;
        n_nodes++;
    } else{
        count_comp++;
        if(strcmp(input, node->input) < 0){
            count_comp++;
            node->left = A_Insert(node->left, input, output);
        } else{
            count_comp++;
            node->right = A_Insert(node->right, input, output);
        }
    }
    node = AutoBalance(node);
    return node;
}

void A_ShowLevels(Avl *node, int n){

    if(!node)
        return;

    if(n > altura)
        altura = n;
        
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

    A_ShowLevels(node->left, n+1);
    A_ShowLevels(node->right, n+1);
}

int GetLevel (Avl *node){
    if(!node)
        return 0;
    else{
        count_comp++;
        int l = GetLevel(node->left);
        int r = GetLevel(node->right);
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

void CalculateBF (Avl *node){
    if(node){
        count_comp++;
        node->bf = GetLevel(node->left) - GetLevel(node->right) ;
        CalculateBF(node->left);
        CalculateBF(node->right);
    }
}

Avl* AutoBalance(Avl *node){ //Balance after insert
    if(node) {   
        count_comp++;     
        CalculateBF(node);
        if(node->bf < 0){
            if(node->right->bf < 0){
                node = A_RotateLeft(node);
            } else if (node->right->bf > 0){
                node->right = A_RotateRight(node->right);
                node = A_RotateLeft(node);
            }
        }
        if(node->bf > 1){
            if(node->left->bf > 0){
                node = A_RotateRight(node);
            } else if (node->left->bf < 0){
                node->left = A_RotateLeft(node->left);
                node = A_RotateRight(node);
            }
        }
    }
    return node;
}

Avl* Balance(Avl *node){
    if(node){
        count_comp++;
        node->left = Balance(node->left);
        node->right = Balance(node->right);

        if(node->bf < -1){
            count_comp++;
            if(node->right->bf < -1){
                count_comp++;
                node = A_RotateLeft(node);
            } else if (node->right->bf > 1){
                count_comp++;
                node->right = A_RotateRight(node->right);
                node = A_RotateLeft(node);
            }
        }
        else if(node->bf > 1){
            count_comp++;
            if(node->left->bf > 1){
                count_comp++;
                node = A_RotateRight(node);
            } else if (node->left->bf < -1){
                count_comp++;
                node->left = A_RotateLeft(node->left);
                node = A_RotateRight(node);
            }
        }
    }
    return node;
}

Avl* A_RotateLeft(Avl *node) {
    n_rotacoes++;
    Avl *tmp;
    tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    node = tmp;
    return node;
}

Avl* A_RotateRight(Avl *node) {
    n_rotacoes++;
    Avl *tmp;
    tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    node = tmp;
    return node;
}

int A_Search(Avl **root, char **input){
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
            return A_Search(&(*root)->left, input);
        } else {
            count_comp++;
            return A_Search(&(*root)->right, input);
        }
    }
}