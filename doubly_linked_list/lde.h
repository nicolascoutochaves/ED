#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 30

typedef struct Product{
    char name[MAXCHAR];
    unsigned int code;
    float price;
}Product;

typedef struct Node{
    Product product;
    struct Node *prev;
    struct Node *next;
}Node;

Node* Init();

Node* Add(Node *list, Product data);

Node* Remove(Node *list, unsigned int code);

void Print(Node *list);

void PrintReverse(Node *list);

Node* Destroy(Node *list);
