#include<stdio.h>
#define MAX 5
int queue[MAX];
int left=-1;
int right=-1;

void insert_right()
{
    int value;
    printf("ENTER THE VALUE TO BE ADDED:");
    scanf("%d",&value);
    if((left== 0 && right==MAX-1) || (left==right+1))
    {
        printf("QUEUE OVERFLOW");
        return;
    }
    if(left==-1)
    {
        left=0;
        right=0;
    }
    else if(left!=0 && right==MAX-1)
    {
        right=0;
        queue[right]=value;
    }
    else
    {
        if(right==MAX-1)
            right=0;
        else
            right=right+1;
    }
    queue[right]=value;
}   
void insert_left()
{
    int value;
    printf("\nENTER THE VALUE TO BE ADDED:");
    scanf("%d",&value);
    if((left==0 && right==MAX-1) || (left==right+1))
    {
        printf("QUEUE OVERFLOW\n");
        return;
    }
    if(left==-1)
    {
        left=0;
        right=0;
    }
    else
    {
        if(left==0)
            left=MAX-1;
        else
            left=left-1;
    }
    queue[left]=value;
}
void delete_at_left()
{
    if(left==-1)
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    printf("\nTHE DELETED ELEMENT IS %d",queue[left]);
    if(left==right)
    {
        left=-1;
        right=-1;
    }
    else
    {
        if(left==MAX-1)
            left=0;
        else
            left=left+1;
    }
}
void delete_at_right()
{
    if(left==-1)
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }   
    printf("THE DELETED ELEMENT IS %d\n",queue[right]);
    if(left==right)
    {
        left=-1;
        right=-1;
    }
    else 
    {
        if(right==0)
                right=MAX-1;
        else
            right=right-1;
    }
}
void print()
{
    int front=left,rear=right;
    if(front==-1)
    {
        printf("\nQUEUE IS EMPTY");
        return;
    }
    printf("THE ELEMENTS OF THE QUEUE ARE:\n");
    if (front<=rear)
    {
        while(front<=rear)
        {
            printf("%d ",queue[front]);
            front++;
        }
    }
    else
    {
        while (front<=MAX-1)
        {
            printf("%d ",queue[front]);
            front++;
        }
        front=0;
        while (front<=rear)
        {
            printf("%d ",queue[front]);
            front++;
        }
    }
    printf("\n");
}
void input_deque()
{
    int option;
    do
    {
        printf("\nINPUT RESTRICTED DEQUE:-\n");
        printf("\nMENU\n1.INSERT AT RIGHT\n2.DELETE AT LEFT\n3.DELETE AT RIGHT\n4.PRINT QUEUE\n5.EXIT");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&option);
        switch (option)
        {
            case 1:
                insert_right();
                break;
            case 2:
                delete_at_left();
                break;
            case 3:
                delete_at_right();
                break;
            case 4:
                print();
                break;
            case 5:
                break;
        }
    } while (option!=5);
}
void output_deque()
{
    int option;
    do
    {
        printf("\nOUTPUT RESTRICTED DEQUE:-\n");
        printf("\nMENU\n1.INSERT AT RIGHT\n2.INSERT AT LEFT\n3.DELETE AT LEFT\n4.PRINT QUEUE\n5.EXIT");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&option);
        switch (option)
        {
            case 1:
                insert_right();
                break;
            case 2:
                insert_left();
                break;
            case 3:
                delete_at_left();
                break;
            case 4:
                print();
                break;
            case 5:
                break;
        }
    } while (option!=5);
}
int main()
{
    int option;
    printf("\n1.INPUT RESTRICTED DEQUE.\n");
    printf("2.OUTPUT RESTRICTED DEQUE.\n");
    printf("\nENTER YOUR OPTION:");
    scanf("%d",&option);
    switch (option)
    {
    case 1:
        input_deque();
        break;
    case 2:
        output_deque();
        break;
    }
    return 0;
}