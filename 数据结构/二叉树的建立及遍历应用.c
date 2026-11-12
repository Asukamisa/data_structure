#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

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
    if (scanf("%c", &ch) != 1) {  // ③ 读一个字符，检查返回值
        return NULL;              //    EOF/失败 → 空树
    }
    if (ch == '#') {              // ④ 空节点判 '#'
        return NULL;
    }
    BiTree T = (BiTree)malloc(sizeof(BiTNode));
    if (!T) { perror("malloc"); exit(1); }
    T->data   = ch;
    T->lchild = build();
    T->rchild = build();
    return T;
}


int main()
{
    BiTree T;
    T = build();
    printf("先序遍历：");
    First(T);
    printf("\n");
    printf("中序遍历：");
    central(T);
    printf("\n");
    printf("后序遍历：");
    Last(T);
    printf("\n");
    return 0;
}