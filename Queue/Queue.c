#include <stdio.h>
#define SIZE 5
typedef struct  {
    int data[SIZE];
    int front;
    int count;
} Queue;

void InitQueue(Queue* Q)
{
    Q->front = 0;
    Q->count = 0;
}

int QueueEmpty(Queue* Q)
{
    return Q->count == 0;
}

void QueueAppend(Queue* Q,int e)
{
    if(Q->count == SIZE)
    {
        printf("队满\n");
        return;
    }
    Q->data[(Q->front + Q->count) % SIZE] = e;
    Q->count++;
}

void QueueDelete(Queue* Q,int* e)
{
    if(Q->count == 0)
    {
        printf("队空\n");
        return;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % SIZE;
    Q->count--;
}

int main()
{
    
}