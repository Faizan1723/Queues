#include<stdio.h>
#define MAX 3
int queue[MAX];
int front=-1;
int rear=-1;

void insert_element()
{
    int value;   
    if((front==0 && rear==MAX-1) || (front!=0 && rear==front-1))
        printf("QUEUE OVERFLOW\n");
    else 
    {
        printf("ENTER THE ELEMENT TO BE INSERTED IN THE QUEUE:");
        scanf("%d",&value);
        if(front==-1 && rear==-1)
        {
            front=rear=0;
            queue[rear]=value;
        }
        else if(front!=0 && rear==MAX-1)
        {
            rear=0;
            queue[rear]=value;
        }
        else
        {
            rear++;
            queue[rear]=value;
        }
    }
}
void delete_element()
{
    if(front==-1 && rear==-1)
        printf("QUEUE UNDERFLOW\n");
    else
    {    printf("THE ELEMENT DELETED IS %d\n",queue[front]);
        if(front==rear)
            front=rear=-1;
        else
        {
            if(front==MAX-1)
                front=0;
            else
                front++;
        }
    }
}
void peek()
{
    if(front==-1)
        printf("QUEUE IS EMPTY\n");
    else
    {
        printf("THE FIRST ELEMENT OF THE QUEUE IS %d\n",queue[front]);
    }
}
void print()
{
    int i;
    if(front==-1 && rear==-1)
        printf("THE QUEUE IS EMPTY.\n");
    else
    {
        printf("THE QUEUE IS:-\n");
        if(front==rear)
            printf("%d\n",queue[front]);
        else if(front<rear)
        {
            for(i=front;i<=rear;i++)
                printf("%d ",queue[i]);
        }
        else
        {
            for(i=front;i<MAX;i++)
                printf("%d ",queue[i]);
            for (i=0;i<=rear;i++)
                printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main()
{
    int option;
    int value;
    do
    {
        printf("\nMENU:-\n1.INSERT ELEMENT IN QUEUE\n2.DELETE ELEMENT IN QUEUE\n3.PEEK\n4.PRINT QUEUE\n5.EXIT\n");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            insert_element();
            break;
        case 2:
            delete_element();
            break;
        case 3:
            peek();
            break;
        case 4:
            print();
            break;
        case 5:
            break;
        }
    }while(option!=5);

    return 0;
}