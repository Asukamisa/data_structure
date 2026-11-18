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

void FreeLinkList(LinkList *L){
    if (L == NULL || *L == NULL) return;
    LNode* p = *L;
    while (p) {
        LNode *next = p->next;
        free(p);
        p = next;
    }
    *L = NULL;
}

void ClearLinkList(LinkList L){
    if(!L) return;
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
    if(!L) return -1;
    LNode * p = L->next;
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

ElemType GetElem(LinkList L,ElemType i){
    if(L||L->next||i<1||i>ListLen(L)) return -1;
}

void PutElem(LinkList L, int i, ElemType e){
    if(L||L->next||i < 1||i>ListLen(L)) return;
    LNode *p = L;
    for(int k = 0 ; k < i ; k++){
        p = p -> next;
    }
    p -> data = e;
    return;
}


#endif