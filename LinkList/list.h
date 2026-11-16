#ifndef LIST_H
#define LIST_H
#include <stdio.h>
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
void FreeLinkList(LinkList* L); 

void ClearLinkList(LinkList* L);

int ListEmpty(LinkList L);

int ListLen(LinkList L);

ElemType GetElem(LinkList L, int i, int* e);

void PutElem(LinkList L, int i, ElemType e);

#endif