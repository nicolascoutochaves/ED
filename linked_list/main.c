#include "data.h"
int main(){
    ptList *ptlist;
    Product data;
    FILE *file;
    char operation = '\0';
    char op =  's';
    ptlist = InitProduct();
    while (operation != 'e'){
        operation = '\0';
        op = 'y';
        printf("Enter the operation:\n\n");
        printf("a - Add product\n");
        printf("r - Remove product\n");
        printf("p - Print List\n");
        printf("f - Find product\n");
        printf("l - Load list\n");
        printf("s - Save list\n");
        printf("e - Exit program\n");
        scanf(" %c", &operation);
        operation = tolower(operation);
        printf("\n");
        switch (operation){
            case 'a':
            while (op == 'y'){
                printf("\nEnter the code of the product: ");
                scanf("%d", &data.code);
                printf("Enter the name of the product: ");
                scanf("%s", data.name);
                printf("Enter the price of the product: ");
                scanf("%f", &data.price);
                ptlist = AddProduct(ptlist, data);
                printf("Do you want to add more products? (y/n): ");
                scanf(" %c", &op);
                op = tolower(op);
                printf("\n");
            }
                break;
            case 'r':
                printf("Enter the code of the product to be removed: ");
                scanf("%d", &data.code);
                ptlist = RemoveProduct(ptlist, data.code);
                break;
            case 'p':
                Print(ptlist);
                break;
            case 'f':
                printf("Enter the code of the product to be find: ");
                scanf("%d", &data.code);
                SearchProduct(ptlist, data.code);
                break;
            case 'l':
                ptlist = LoadData(ptlist);
                break;
            case 's':
                SaveData(ptlist);
                break;
            case 'e':
                break;
            default:
                puts("Invalid Operation!");
        }    
    }
    

    return 0;
}