#include "stack.h"

//Contigous stack Functions:

void InitContinous(int *bottom, int *size, int *top){
    *bottom = 0;
    *size = -1;
    *top = -1;
}

int IsFullContinous(int *top, int *size){
    return (*top == *size - 1);
}

int IsEmptyContinous(int *top){
    return (*top == -1);
}

int PushContinous(Product stack[], int *top, int *size, Product data){
    if(IsFullContinous(top, size)){
        puts("Stack is full");
        return 0;
    }
    stack[++(*top)] = data;
    return 1;
}

int PopContinous(Product stack[], int *top, int base, int *size, Product *data){
    if(IsEmptyContinous(top)){
        puts("Stack is empty");
        return 0;
    }
    *data = stack[(*top)--];
    return 1;
}

int SearchContinous(Product stack[], int *top, int *size, Product *data){
    if(IsEmptyContinous(top)){
        puts("Stack is empty");
        return 0;
    }
    *data = stack[*top];
    return 1;
}

int PrintContinous(Product stack[], int *top, int *size){
    if(IsEmptyContinous(top)){
        puts("Stack is empty");
        return 0;
    }
    for(int i = *top; i >= 0; i--){
        printf("Product: %s\n", stack[i].name);
        printf("ID: %d\n", stack[i].id);
        printf("Price: %.2f\n", stack[i].price);
    }
    return 1;
}

int DestroyContinous(Product stack[], int *top){
    if(IsEmptyContinous(top)){
        puts("Stack is empty");
        return 0;
    }
    *top = -1;
    return 1;
}

//Linked stack Functions:

Node* Init(){
    return NULL;
}

int IsEmpty(Node *top){
    return (top == NULL);
}

Node* Push(Node *top, Product data){
    Node *newNode = calloc(sizeof(Node), 1);
    if(newNode == NULL){
        puts("Memory allocation failed");
        return top;
    }

    newNode->data = data;
    newNode->next = top;
    return newNode;
}

int Pop(Node **top, Product *data){
    if(IsEmpty(*top)){
        puts("Stack is empty");
        return 0;
    }
    Node *temp = *top;
    *data = temp->data;
    *top = temp->next;
    free(temp);
    return 1;
}

Node* InsertOrdered(Node *top, Product data){ //insert in descending order
    Node *newNode = calloc(sizeof(Node), 1);
    if(newNode == NULL){
        puts("Memory allocation failed");
        return top;
    }

    newNode->data = data;
    if(IsEmpty(top) || top->data.id < data.id){
        newNode->next = top;
        return newNode;
    }

    Node *current = top;
    while(current->next != NULL && current->next->data.id > data.id){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return top;
}

Node Search(Node *top){
    if(IsEmpty(top)){
        puts("Stack is empty");
        return *top;
    }
    return *top;
}

int Print(Node *top){
    if(IsEmpty(top)){
        puts("Stack is empty");
        return 0;
    }
    Node *current = top;
    while(current != NULL){
        printf("Product: %s\n", current->data.name);
        printf("ID: %d\n", current->data.id);
        printf("Price: %.2f\n", current->data.price);
        current = current->next;
    }
    return 1;
}

Node* Destroy(Node *top){
    Node *aux;
    while (top != NULL){
        aux = top;
        top = top->next;
        free(aux);
    }
    return NULL;
}