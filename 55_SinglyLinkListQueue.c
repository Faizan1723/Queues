#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* front=NULL;
struct node* rear=NULL;

void insert_element()
{
    int num;
    printf("ENTER THE ELEMENT TO BE INSERTED:");
    scanf("%d",&num);
    struct node* temp=malloc(sizeof(struct node));
    temp->data=num;
    temp->link=NULL;
    if(front==NULL && rear==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->link=temp;
        rear=temp;
    }
}
int delete_element()
{
    int val;
    struct node* ptr=front;
    if(front==NULL)
        printf("QUEUE UNDERFLOW\n");
    else
    {
        front=front->link;
        printf("\nTHE DELETED ELEMENT IS %d\n",ptr->data);
        free(ptr);
        ptr=NULL;
        return val;
    }
}
void peek()
{
    if(front!=NULL)
        printf("THE FIRST ELEMENT OF THE QUEUE IS %d\n",front->data);
    else
        printf("\nEMPTY QUEUE\n");
}
void print()
{
    struct node* ptr=front;
    if(front==NULL)
        printf("EMPTY QUEUE\n");
    else
        printf("THE QUEUE IS:-\n");
        while(ptr!=rear)
        {
            printf("%d ",ptr->data);
            ptr=ptr->link;
        }
        printf("%d",ptr->data);
        printf("\n");
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
            value=delete_element();
            break;
        case 3:
            peek();
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