#include "list.h"
#include <stdlib.h>

LinkList InitLinkList()
{
    LinkList L;
    if (!(L = (LinkList)malloc(sizeof(LNode)))) {
        return NULL;
    }
    L->next = NULL;
    return L;
}