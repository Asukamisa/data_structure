#include "BiTree.h"
#include "Stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>



void First(BiTree T)
{
    if (T) {
        printf("%c ", T->data);
        First(T->lchild);
        First(T->rchild);
    }
}

void central(BiTree T)
{
    if (T) {
        central(T->lchild);
        printf("%c ", T->data);
        central(T->rchild);
    }
}

void Last(BiTree T)
{
    if (T) {
        Last(T->lchild);
        Last(T->rchild);
        printf("%c ", T->data);
    }
}

BiTree build(void)
{
    char ch;
    if (scanf(" %c", &ch) != 1) {  
        return NULL;              
    }
    if (ch == '#') {              
        return NULL;
    }
    BiTree T = (BiTree)malloc(sizeof(BiTNode));
    if (!T) { perror("malloc"); exit(1); }
    T->data   = ch;
    T->lchild = build();
    T->rchild = build();
    return T;
}

int Leaves(BiTree T, int *count)
{
    if (T) {
        if (!T->lchild && !T->rchild) {
            printf("%c ", T->data);
            (*count)++;
        }
        Leaves(T->lchild, count);
        Leaves(T->rchild, count);
    }
    return *count;
}

void Layer(BiTree T)
{
    if (!T) { printf("空树\n"); return; }
    LinkList head = (LinkList)malloc(sizeof(ListNode));
    head->next = NULL;
    LinkList Tnode = (LinkList)malloc(sizeof(ListNode));
    head->next = Tnode;
    Tnode->data = *T;
    Tnode->next = NULL;
    while(head->next != NULL) {
        printf("%c ", head->next->data.data);
        LinkList p = head->next;
        head->next = head->next->next;
        if (p->data.lchild) inlist(head, p->data.lchild);
        if (p->data.rchild) inlist(head, p->data.rchild);
        free(p);
    }
    return;
}

// 【核心：非递归中序遍历】
void InOrderNonRec(BiTree T) {
    SqStack st;
    InitStack(&st);
    BiTNode *p = T;
    while (p != NULL || !StackEmpty(&st)) {
        // 1. 一直往左走，沿途结点入栈
        while (p != NULL) {
            Push(&st, p);
            p = p->lchild;
        }
        // 2. 左为空，弹出栈顶，访问
        Pop(&st, &p);
        printf("%c ", p->data);
        // 3. 转向右子树
        p = p->rchild;
    }
}