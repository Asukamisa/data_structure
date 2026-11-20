#ifndef STACK_H
#define STACK_H
#include "BiTree.h"
#define MAXSIZE 100

typedef struct {
    BiTNode* data[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack *s);
int StackEmpty(SqStack *s);
int Push(SqStack *s, BiTNode *p);
int Pop(SqStack *s, BiTNode **p);

#endif