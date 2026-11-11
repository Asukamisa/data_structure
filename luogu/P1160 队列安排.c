#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prior;
    struct DNode *next;
} DNode, *DLinkList;

int InitDLinkList(DLinkList *L)
{
    *L = (DLinkList)malloc(sizeof(DNode));
    if (*L == NULL) return 0;
    (*L)->data = -1;
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return 1;
}

void InsertDLinkList(DLinkList L, int i, int n, int p)
{
    
    if (L == NULL) return;
    DNode* stu = (DNode*)malloc(sizeof(DNode));
    stu ->data = i;
    stu -> prior = NULL;
    stu->next = NULL;
    if (n == -1) {
        // 插到哑节点之后 = 表头
        stu->next  = L->next;
        if (L->next) L->next->prior = stu;
        stu->prior = L;
        L->next    = stu;
        return;
    }

    DNode *prev = L, *q = L->next;
    while (q && q->data != n) {
        prev = q;
        q = q->next;
    }
    if (q == NULL) return;           // 真·找不到 n，直接返回

    if (p == 0) {
        stu->next  = q;
        stu->prior = q->prior;
        prev->next = stu;
        q->prior   = stu;
    } else if (p == 1) {
        stu->next  = q->next;
        stu->prior = q;
        if (q->next) q->next->prior = stu;
        q->next    = stu;
    }
}

void DeleteDLinkList(DLinkList L,int i)
{
    if (L == NULL) return;
    DNode *prev = L, *q = L->next;
    while (q && q->data != i) {
        prev = q;
        q = q->next;
    }
    if (q == NULL) return;
    prev ->next = q->next;
    if (q->next) q->next->prior = prev;
    free(q);
}

void printfDLinkList(DLinkList L)
{
    L = L->next;
    while(L)
    {
        printf("%d " ,L->data);
        L = L->next;
    }

}

int main()
{
    int N;
    scanf("%d",&N);
    DLinkList L;
    InitDLinkList(&L);

    InsertDLinkList(L,1,-1,1);
    for(int i = 2 ; i < N+1 ; i++)
    {
        int k , p ;
        scanf("%d %d",&k ,&p);
        InsertDLinkList(L,i,k,p);
    }
    int M;
    scanf("%d",&M);
    for(int i = 0 ; i < M ; i++)
    {
        int k;
        scanf("%d",&k);
        DeleteDLinkList(L,k);
    }
    printfDLinkList(L);
    system("pause");
    return 0;
}
