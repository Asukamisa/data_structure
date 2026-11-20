#include "Stack.h"

void InitStack(SqStack *s) {
    s->top = -1;
}

// 判栈空
int StackEmpty(SqStack *s) {
    return s->top == -1;
}

// 入栈
int Push(SqStack *s, BiTNode *p) {
    if (s->top == MAXSIZE - 1)
        return 0;
    s->data[++s->top] = p;
    return 1;
}

// 出栈
int Pop(SqStack *s, BiTNode **p) {
    if (StackEmpty(s))
        return 0;
    *p = s->data[s->top--];
    return 1;
}

