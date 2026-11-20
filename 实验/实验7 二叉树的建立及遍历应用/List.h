#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
    BiTNode data;
    struct ListNode *next;
} ListNode, *LinkList;

void inlist(LinkList head, BiTNode *T);

#endif