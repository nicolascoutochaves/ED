#include "stack.h"

int main(){
    //Contigous stack
    Product stack[10];
    Product data;
    int bottom = -1, size = 10, top = -1;

  /*   InitContinous(&bottom, &size, &top);
    PushContinous(stack, &top, &size, (Product){"Product 1", 1, 10.0});
    PushContinous(stack, &top, &size, (Product){"Product 2", 2, 20.0});
    PrintContinous(stack, &top, &size);
    PopContinous(stack, &top, bottom, &size, &data);
    PrintContinous(stack, &top, &size);
    DestroyContinous(stack, &top);
    PrintContinous(stack, &top, &size); */

    printf("\n\n\n");


    //Linked stack
    Node *sp = Init(); //Stack pointer

    sp = Push(sp, (Product){"Product 1", 1, 10.0});
    sp = Push(sp, (Product){"Product 5", 5, 20.0});
    sp = Push(sp, (Product){"Product 2", 2, 20.0});
    Print(sp);
    printf("\n\n");
    sp = InsertOrdered(sp, (Product){"Product 4", 4, 40.0});
    sp = InsertOrdered(sp, (Product){"Product 3", 3, 30.0});
    sp = InsertOrdered(sp, (Product){"Product 7", 7, 70.0});
    sp = InsertOrdered(sp, (Product){"Product 6", 6, 60.0});
    Print(sp);
    printf("\n\n");
    Pop(&sp, &data);
    Print(sp);
    sp = Destroy(sp);
    Print(sp);
    return 0; 
}