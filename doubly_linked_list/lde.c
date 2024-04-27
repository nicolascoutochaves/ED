#include "lde.h"

Node* Init(){
    return NULL;
}

Node* Add(Node *list, Product data){
    Node *new = calloc(sizeof(Node), 1);
    if(!new){
        puts("Error while allocating memory!");
        return list;
    }
    new->product = data;

    if(!list || list->product.code > new->product.code){
        new->prev = NULL;
        new->next = list;
        if(list)
            list->prev = new;
        return new;
    }
    Node *tmp = list;
    while(tmp->next && new->product.code > tmp->next->product.code)
        tmp = tmp->next;

    new->prev = tmp;
    new->next = tmp->next;
    tmp->next = new;
    if(new->next)
        new->next->prev = new;

    
    return list;
}
void Print(Node *list){
   if(list){
        printf("Name: %s\nCode: %d\nPrice: %02.2f\n", list->product.name, list->product.code, list->product.price);
        printf("Previous: %p\n", list->prev);
        printf("Current: %p\n", list);
        printf("Next: %p\n\n", list->next);

        Print(list->next);
   }
}

void PrintReverse(Node *list){
   if(!list){
        PrintReverse(list->next);
        
        printf("Name: %s\nCode: %d\nPrice: %02.2f\n", list->product.name, list->product.code, list->product.price);
        printf("Previous: %p\n", list->prev);
        printf("Current: %p\n", list);
        printf("Next: %p\n\n", list->next);
   }
}

Node* Destroy(Node *list){
    if(list){
        list = Destroy(list->next);
    }
    free(list);
    return NULL;
}

Node* Remove(Node *list, unsigned int code){
    if(!list){
        puts("List is empty!");
        return list;
    }
    Node *tmp = list;
    while(tmp && tmp->product.code != code)
        tmp = tmp->next;
    if(!tmp){
        puts("Product not found!");
        return list;
    }

    if(tmp == list)
        list = tmp->next;
    if(tmp->prev)
        tmp->prev->next = tmp->next;
    if(tmp->next)
        tmp->next->prev = tmp->prev;
    free(tmp);

    
    return list;
}