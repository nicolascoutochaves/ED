#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 50

typedef struct Product{
    int code;
    char name[MAX_CHAR];
    float price;
} Product;

typedef struct ptList{
    Product product;
    struct ptList *next;
} ptList;

ptList *InitProduct();

ptList *AddProduct(ptList *ptList, Product data);

void Print (ptList *lista);

ptList *RemoveProduct(ptList *ptList, int code);

void SearchProduct(ptList *ptList, int code);

ptList *LoadData(ptList *ptList);

void SaveData(ptList *ptList);