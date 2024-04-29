#include <stdio.h>
#include <stdlib.h>

typedef struct Product{
    char name[100];
    unsigned int id;
    float price;
}Product;

typedef struct Node{
    Product data;
    struct Node *next;
}Node;

//Contigous stack Functions:

void InitContinous(int *bottom, int *size, int *top);

int IsFullContinous(int *top, int *size);

int IsEmptyContinous(int *top);

int PushContinous(Product stack[], int *top, int *size, Product data);

int PopContinous(Product stack[], int *top, int base, int *size, Product *data);

//Return the top element of the stack
int SearchContinous(Product stack[], int *top, int *size, Product *data);

int PrintContinous(Product stack[], int *top, int *size);

int DestroyContinous(Product stack[], int *top);


//Linked stack Functions:

Node* Init();

int IsEmpty(Node *top);

Node* Push(Node *top, Product data);

Node* InsertOrdered(Node *top, Product data);

int Pop(Node **top, Product *data);

Node Search(Node *top);

int Print(Node *top);

Node* Destroy(Node *top);

