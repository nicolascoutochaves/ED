#include "data.h"


ptList *InitProduct(){
    return NULL;
}

ptList *AddProduct(ptList *ptlist, Product data){
    if(ptlist == NULL){
        ptlist = calloc(sizeof(ptList), 1);
        if(ptlist == NULL){
            puts("Error while allocating memory!");
        } else{
                ptlist->product = data;
                ptlist->product.code = data.code;
                strcpy(ptlist->product.name, data.name);
            }
    }else{
        if(data.code < ptlist->product.code){
            ptList *temp = calloc(sizeof(ptList), 1);
            if(temp == NULL){
                puts("Error while allocating memory!");
            } else{
                temp->product = data;
                temp->product.code = data.code;
                strcpy(temp->product.name, data.name);
                temp->next = ptlist;
                ptlist = temp;
            }
        }
        else{
            ptlist->next = AddProduct(ptlist->next, data);
        }
    }
    return ptlist;
}

void Print (ptList *list){
    if (list == NULL){
        puts("Empty list!");
        return;
    } else{
        ptList *temp = list;
        while (temp != NULL){
            printf("Code: %d\n", temp->product.code);
            printf("Name: %s\n", temp->product.name);
            printf("Price: %02.2f\n", temp->product.price);
            temp = temp->next;
        }
    }
}

ptList *RemoveProduct (ptList *ptlist, int code){
    if (ptlist == NULL){
        puts("Empty list!");
        return NULL;
    } else{
        ptList *temp = ptlist;
        ptList *previous = NULL;
        while (temp != NULL && temp->product.code != code){
            previous = temp;
            temp = temp->next;
        }
        if (temp == NULL){
            puts("Product not found!");
            return ptlist;
        } else{
            if (previous == NULL){
                ptlist = temp->next;
            } else{
                previous->next = temp->next;
            }
            free(temp);
            return ptlist;
        }
    }
}

void SearchProduct(ptList *list, int code){
    if (list == NULL){
        puts("Empty list!");
        return;
    } else{
        ptList *temp = list;
        while(temp != NULL && temp->product.code != code){
            temp = temp->next;
        }
        if(temp == NULL){
            puts("Product not found!");
        } else{
            printf("\nCode: %d\n", temp->product.code);
            printf("Name: %s\n", temp->product.name);
            printf("Price: %02.2f\n", temp->product.price);
        }
    }
}
ptList *LoadData(ptList *list){
    FILE *file;
    file = fopen("data.dat", "rb");
    if (file == NULL){
        puts("Error while opening file!");
        return list;
    } else{
        Product data;
        while (fread(&data, sizeof(Product), 1, file) > 0){
            list = AddProduct(list, data);
        }
        fclose(file);
    }
    return list;
}
void SaveData(ptList *list){
    FILE *file;
    file = fopen("data.dat", "wb");
    if (file == NULL){
        puts("Error while opening file!");
        return;
    } else{
        ptList *temp = list;
        while (temp != NULL){
            fwrite(&(temp->product), sizeof(Product), 1, file);
            temp = temp->next;
        }
        fclose(file);
    }
}