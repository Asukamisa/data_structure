#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

LinkList InitLinkList()
{
    LinkList L;
    if (!(L = (LinkList)malloc(sizeof(LNode)))) {
        return NULL;
    }
    L->next = NULL;
    return L;
}
void FreeLinkList(LinkList L){
    LNode* p;
    while (L) {
        p = L;
        L = L->next;
        free(p);
    }
}

void ClearLinkList(LinkList L){
    LNode* p;
    while (L->next) {
        p = L->next;
        L->next = p->next;
        free(p);
    }
}

int ListEmpty(LinkList L){
    return L->next == NULL;
}

int ListLen(LinkList L){
    
}

ElemType GetElem(LinkList L, int i, int* e);

void PutElem(LinkList L, int i, ElemType e);

#endif