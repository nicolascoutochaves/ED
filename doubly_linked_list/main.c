#include "lde.h"

int main(){
    Node *p = Init();
    p = Add(p, (Product){"test 1", 1, 19.99});
    p = Add(p, (Product){"test 2", 2, 700.88});
    p = Add(p, (Product){"test 6", 6, 180.55});
    p = Add(p, (Product){"test 4", 4, 330.85});

    Print(p);
    printf("\n\n\n");
    p = Remove(p, 1);
    Print(p);
    p = Destroy(p);
    Print(p);

    return 0;
}