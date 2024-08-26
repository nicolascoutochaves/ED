#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arvores.h"

Splay* S_Init(Splay *node){
    return NULL;
}

Splay* S_Insert(Splay *node, char input[], char output[]){

    if(!node){
        count_comp++;
        node = calloc(sizeof(Splay), 1);
        int i = 0;
        do{
            if(input[i] == '\n' || input[i] == '\r'){
                input[i] = '\0';
            }
            node->input[i] = tolower(input[i]);
        }
        while(input[i++] && i < STR_MAX-1);

        i = 0;
        do{
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
            node->left = S_Insert(node->left, input, output);
        } else {
            count_comp++;
            node->right = S_Insert(node->right, input, output);
        }
    }
    return S_Splay(node, input);
}

void S_ShowLevels(Splay *node, int n){

    if(!node)
        return;
    if(n > altura)
        altura = n;

    for(int i = 0; i <= n; i++) {
        printf("=");
    }

    printf(" %s\n", node->input);

    S_ShowLevels(node->left, n+1);
    S_ShowLevels(node->right, n+1);
}


Splay* RotateLeft(Splay *node) {
    n_rotacoes++;
    Splay *tmp;
    tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    node = tmp;
    return node;
}

Splay* RotateRight(Splay *node) {
    n_rotacoes++;
    Splay *tmp;
    tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    node = tmp;
    return node;
}

int Splay_GetLevel(Splay *node){
    if(!node)
        return 0;
    int left = Splay_GetLevel(node->left);
    int right = Splay_GetLevel(node->right);
    return left > right ? left + 1 : right + 1;
}

Splay* S_Splay (Splay *root, char input[]){
    
    count_search++;
   // Base cases: root is NULL or key is present at root
    if (root == NULL || !(strcmp(root->input, input))){
        count_comp++;
        return root;
    }
 
    // Key lies in left subtree
    if (strcmp(input, root->input) < 0) {
        count_comp++;
        
        // Key is not in tree, we are done
        if (root->left == NULL){
            count_comp++;
            return root;
        }
 
        // Zig-Zig (Left Left)
        if (strcmp(input, root->left->input) < 0) {
            count_comp++;
            // First recursively bring the key as root of left-left
            root->left->left = S_Splay(root->left->left, input);
 
            // Do first rotation for root, second rotation is done after else
            root = RotateRight(root);
        } else if (strcmp(input, root->left->input) > 0) // Zig-Zag (Left Right)
        {
            count_comp++;
            // First recursively bring the key as root of left-right
            root->left->right = S_Splay(root->left->right, input);
 
            // Do first rotation for root->left
            if (root->left->right != NULL){
                count_comp++;
                root->left = RotateLeft(root->left);
            }
        }
 
        // Do second rotation for root
        if(root->left == NULL) {
            count_comp++;
            return root;
        } else {
            count_comp++;
            return RotateRight(root);
        }

    } else // Key lies in right subtree
    {
        count_comp++;

        // Key is not in tree, we are done
        if (root->right == NULL){
            count_comp++;
            return root;
        }
 
        // Zag-Zig (Right Left)
        if (strcmp(input, root->right->input) < 0) {
            count_comp++;
            // Bring the key as root of right-left
            root->right->left = S_Splay(root->right->left, input);
 
            // Do first rotation for root->right
            if (root->right->left != NULL){
                count_comp++;
                root->right = RotateRight(root->right);
            }

        } else if (strcmp(input, root->right->input) > 0)// Zag-Zag (Right Right)
        {
            count_comp++;
            // Bring the key as root of right-right and do first rotation
            root->right->right = S_Splay(root->right->right, input);
            root = RotateLeft(root);
        }
 
        // Do second rotation for root
        if(root->right == NULL) {
            count_comp++;
            return root;
        } else {
            count_comp++;
            return RotateLeft(root);
        }

    }
}

int S_Search(Splay **root, char **data){
    *root = S_Splay(*root, *data);
    if((*root) && !strcmp((*root)->input, *data)){
        *data = (*root)->output;
        count_comp++;
        return 1;
    }
    return 0;
}