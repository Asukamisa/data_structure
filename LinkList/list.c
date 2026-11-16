#include "list.h"
#include <stdlib.h>

int main(void){
    LinkList L = InitLinkList();
    FreeLinkList(L);
    return 0;
}