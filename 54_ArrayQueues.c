#include<stdio.h>
#define MAX 100
int queue[MAX];
int front=-1;
int rear=-1;

void insert_element()
{
    int value;
    printf("ENTER THE ELEMENT TO BE INSERTED IN THE QUEUE:");
    scanf("%d",&value);
    if(rear==MAX-1)
        printf("QUEUE OVERFLOW\n");
    else if(front==-1 && rear==-1)
        front=rear=0;
    else
        rear++;
    queue[rear]=value;   
}
int delete_element()
{
    int value;
    if(front==-1 || front>rear)
    {
        printf("\nQUEUE UNDERFLOW\n");
        return -1;
    }
    else
    {
        value=queue[front];
        front++;
        if(front>rear)
            front=rear=-1;
        return value;
    }
}
int peek()
{
    if(front==-1 || front>rear)
    {
        printf("QUEUE IS EMPTY\n");
        return -1;
    } 
    else
    {
        return queue[front];
    }
}
void print()
{
    int i;
    printf("\n");
    if(front==-1 || front>rear)
        printf("QUEUE IS EMPTY\n");
    else
    {
        printf("THE QUEUE IS:-\n");
        for(i=front;i<=rear;i++)
            printf("%d ",queue[i]);
        printf("\n");
    }
}
int main()
{
    int option,value;
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
            value=delete_element();
            if(value!=-1)
            {
                printf("\nTHE DELETED ELEMENT IS %d\n",value);
            }
            break;
        case 3:
            value=peek();
            if(value!=-1)
                printf("THE FIRST ELEMENT IN THE QUEUE IS %d",value);
            break;
        case 4:
            print();
            break;
        default:
            break;
        }
    }while(option!=5);

    return 0;
}