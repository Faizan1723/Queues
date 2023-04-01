#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int* Q;
};

void create(struct Queue* q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));
}
void enqueue(struct Queue* q,int x)
{
    if(q->rear==q->size-1)
    {
        printf("THE QUEUE IS FULL\n");
        return;
    }
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue* q)
{
    int x=-1;
    if(q->front==q->rear)
    {
        printf("EMPTY QUEUE\n");
        return x;
    }
    else
    {
        q->front++;
        x=q->Q[q->front];
        return x;
    }
}

void display(struct Queue q)
{
    for(int i=q.front+1;i<=q.rear;i++)
    {
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}
int main()
{
    struct Queue q;
    printf("ENTER SIZE OF THE QUEUE:");
    scanf("%d",&q.size);

    create(&q,q.size);
    enqueue(&q,5);
    enqueue(&q,10);
    enqueue(&q,15);

    display(q);

    printf("%d",dequeue(&q));
    return 0;
}