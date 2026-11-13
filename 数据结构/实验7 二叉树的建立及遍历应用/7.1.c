#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct ListNode {
    BiTNode data;
    struct ListNode *next;
} ListNode, *LinkList;

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

// 栈结构（存二叉树结点指针）
#define MAXSIZE 100
typedef struct {
    BiTNode* data[MAXSIZE];
    int top;
} SqStack;

// 栈初始化
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
        printf("%d ", p->data);
        // 3. 转向右子树
        p = p->rchild;
    }
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

    int count = 0;
    printf("叶子结点：");
    Leaves(T, &count);
    printf("\n");
    printf("叶子结点数：%d", count);
    printf("\n");

    printf("层序遍历：");
    Layer(T);

    return 0;
}