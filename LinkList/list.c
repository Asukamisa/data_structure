#include "list.h"
#include <stdlib.h>

int main(void){
    LinkList L = InitLinkList();
    printf("%d\n", ListLen(L));
    FreeLinkList(&L);

    printf("%d\n", ListLen(L));

    L = InitLinkList();
    printf("%d\n", ListLen(L));
    system("pause");
    return 0;
}

