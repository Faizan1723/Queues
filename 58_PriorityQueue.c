#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int priority;
    struct node* link;
};
struct node* add_node(struct node* head)
{
    int data,priority;
    printf("\nENTER THE DATA AND IT'S PRIORITY:-\n");
    scanf("%d %d",&data,&priority);

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->priority=priority;

    if(head==NULL || head->priority>priority)
    {
        temp->link=head;
        head=temp;
    }
    else
    {
        struct node* ptr=head;
        while (ptr->link != NULL && ptr->link->priority <= priority)
        {
            ptr=ptr->link;
        }
        temp->link=ptr->link;
        ptr->link=temp;
    }
    return head;
}
struct node* delete_node(struct node* head)
{
    struct node* temp=head;
    printf("\nTHE DELETED DATA IS %d\n",temp->data);
    head=head->link;
    free(temp);
    temp=NULL;
    return head;
}
void display(struct node* head)
{
    struct node* ptr=head;
    if(head==NULL)
    {
        printf("\nTHE QUEUE IS EMPTY\n");
    }
    else
    {
        printf("\nTHE PRIORITY QUEUE IS:-\n\n");
        while (ptr!=NULL)
        {
            printf("%d\t[PRIORITY-%d]\n",ptr->data,ptr->priority);
            ptr=ptr->link;
        }
    }
}
int main()
{
    struct node* head=NULL;

    int option;
    do
    { 
        printf("\nMENU:-\n1.INSERT DATA.\n2.DELETE DATA.\n3.DISPLAY QUEUE.\n4.EXIT\n");
        printf("ENTER YOUR CHOICE:");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            head=add_node(head);
            break;
        case 2:
            head=delete_node(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            break;
        }
    } while (option!=4);

    return 0;  
}