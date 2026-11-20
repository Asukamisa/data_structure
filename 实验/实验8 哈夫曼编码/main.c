#include <stdio.h>
#include <stdlib.h>

typedef struct HFNode
{
    double weight;
    int parent, lchild, rchild;
} HFNode;

typedef struct HFTree
{
    int root;
    HFNode Node[15];
} HFTree;

typedef struct{
    int* bit;
    int start;
    double weight;
}code;

int* reindex(HFTree* HT, int n){
    int *index = (int*)malloc(sizeof(int)*2);
    index[0] = -1;
    index[1] = -1;
    for(int i = 0; i < n; i++)
    {
        if(HT->Node[i].parent != -1)
        {
            continue;
        }

        if(index[0] == -1){
            index[0] = i;
        }

        else if(HT->Node[i].weight < HT->Node[index[0]].weight){
            index[1] = index[0];
            index[0] = i;
        }

        else if(index[1] == -1 || HT->Node[i].weight < HT->Node[index[1]].weight)
            index[1] = i;
    }
    return index;
}

HFTree *buildHFTree(int n,double *w){
    HFTree* HT = (HFTree*)malloc(sizeof(HFTree));
    for(int i = 0; i < n; i++)
    {
        HT->Node[i].weight = w[i];
        HT->Node[i].parent = -1;
        HT->Node[i].lchild = -1;
        HT->Node[i].rchild = -1;
    }
    for(int i = n; i < 2*n-1; i++)
    {
        int *index = reindex(HT, i);
        HT->Node[i].weight = HT->Node[index[0]].weight + HT->Node[index[1]].weight;
        HT->Node[i].parent = -1;
        HT->Node[i].lchild = index[0];
        HT->Node[i].rchild = index[1];
        HT->Node[index[0]].parent = i;
        HT->Node[index[1]].parent = i;
        
    }
    HT->root = 2*n-2;
    return HT;
}


void buildHTcode(HFTree *HT,int n,code* HTcode)
{
    for(int i = 0; i < n; i++)
    {
        HTcode[i].weight = HT->Node[i].weight;
        HTcode[i].bit = (int*)malloc(sizeof(int) * n);
        HTcode[i].start = n;                 

        int c = i;
        int p = HT->Node[i].parent;
        while(p != -1)
        {
            HTcode[i].bit[--HTcode[i].start] = (HT->Node[p].lchild == c) ? 0 : 1;
            c = p;
            p = HT->Node[p].parent;
        }
    }
}

void printHFTree(HFTree *HT,int n){
    printf("%-10s%-10s%-10s%-10s%-10s","index","weight","parent","lchild","rchild");
    printf("\n");
    for(int i = 0 ; i < 2*n-1;i++){
        printf("%-10d%-10.2f%-10d%-10d%-10d\n" ,i,HT->Node[i].weight,HT->Node[i].parent,HT->Node[i].lchild,HT->Node[i].rchild);
    }

}

void printHTcode(code* HTcode,char* str,int n){
    double wpl = 0;
    for(int i = 0; i < n; i++)
    {
        printf("%-10c%-10.2f  ", str[i], HTcode[i].weight);
        for(int j = HTcode[i].start; j < n; j++)
            printf("%d", HTcode[i].bit[j]);
        printf("\n");
        wpl += HTcode[i].weight * (n - HTcode[i].start);
    }
    printf("WPL = %.2f\n", wpl);
}

int main()
{
    int n = 8;
    char str[8] = {'a','b','c','d','e','f','g','h'};
    double w[8] = {0.07,0.19,0.02,0.06,0.32,0.03,0.21,0.10};
    HFTree *HT = buildHFTree(n,w);
    code* HTcode =(code*)malloc(sizeof(code)*n);
    buildHTcode(HT,n,HTcode);
    printHFTree(HT,8);
    printHTcode(HTcode,str,8);


    for(int i = 0; i < n; i++)
        free(HTcode[i].bit);
    free(HTcode);
    free(HT);
     return 0;
}