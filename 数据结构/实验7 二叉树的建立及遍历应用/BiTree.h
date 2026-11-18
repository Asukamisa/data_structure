#ifndef BITREE_H
#define BITREE_H

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void First(BiTree T);
void central(BiTree T);
void Last(BiTree T);
BiTree build(void);
int Leaves(BiTree T, int *count);
void Layer(BiTree T);
void InOrderNonRec(BiTree T);
#endif

