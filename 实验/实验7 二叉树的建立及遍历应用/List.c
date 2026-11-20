#include "BiTree.h" 
#include "List.h"
#include <stdlib.h>



void inlist(LinkList head, BiTNode *T)
{
    while (head->next != NULL) {
        head = head->next;
    }
    LinkList Tnode = (LinkList)malloc(sizeof(ListNode));
    Tnode->data = *T;
    Tnode->next = NULL;
    head->next = Tnode;
    return;
}
