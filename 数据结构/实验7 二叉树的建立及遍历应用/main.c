#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

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

    int count = 0;
    printf("叶子结点：");
    Leaves(T, &count);
    printf("\n");
    printf("叶子结点数：%d", count);
    printf("\n");

    printf("层序遍历：");
    Layer(T);

    printf("\n");
    printf("非递归中序遍历：");
    InOrderNonRec(T);
    system("pause");
    //AB##CD##EF###
    return 0;
}