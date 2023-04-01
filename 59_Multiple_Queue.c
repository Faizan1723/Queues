#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

int queue[MAX];
int frontA=-1;
int rearA=-1;
int frontB=MAX;
int rearB=MAX;

void insertA()
{
    int data;
    if(rearA==rearB-1)
    {
        printf("QUEUE OVERFLOW\n");
    }
    printf("\nENTER THE DATA TO BE ADDED IN QUEUE A:");
    scanf("%d",&data);
    if(frontA==-1 && rearA==-1)
    {
        frontA=0;
        rearA=0;
        queue[rearA]=data;
    }
    else
    {
        queue[++rearA]=data;
    }
}

void insertB()
{
    int data;
    if(rearA==rearB-1)
    {
        printf("QUEUE OVERFLOW\n");
    }
    printf("\nENTER THE DATA TO BE ADDED IN QUEUE B:");
    scanf("%d",&data);
    if(frontB==MAX && rearB==MAX)
    {
        frontB=MAX-1;
        rearB=MAX-1;
        queue[rearB]=data;
    }
    else
    {
        queue[--rearB]=data;
    }
}

void deleteA()
{
    if(frontA==-1 && rearA==-1)
        printf("\nQUEUE UNDERFLOW");
    else
    {
        printf("THE DELETED DATA OF THE QUEUE IS %d",queue[frontA]);
        frontA++;
        if(frontA>rearA)
        {
            frontA=-1;
            rearA=-1;
        }
    }
}

void deleteB()
{
    if(frontB==MAX && rearB==MAX)
        printf("\nQUEUE UNDERFLOW");
    else
    {
        printf("THE DELETED DATA OF THE QUEUE IS %d",queue[frontB]);
        frontB--;
        if(frontB<rearB)
        {
            frontB=MAX;
            rearB=MAX;
        }
    }
}

void displayA()
{
    if(frontA==-1)
        printf("\nQUEUE IS EMPTY\n");
    else
    {
        printf("\nQUEUE A IS:-\n");
        for(int i=frontA;i<=rearA;i++) 
        {
            printf("%d ",queue[i]);
        }  
    }
}

void displayB()
{
    if(frontB==MAX)
        printf("\nQUEUE IS EMPTY\n");
    else
    {
        printf("\nQUEUE B IS:-\n");
        for(int i=frontB;i>=rearB;i--) 
        {
            printf("%d ",queue[i]);
        }  
    }
}

int main()
{
    int option;
    do
    {
        printf("\nMENU:-\n1.ADD IN QUEUE A.\n2.ADD IN QUEUE B.\n3.DELETE FROM QUEUE A.\n4.DELETE FROM QUEUE B.\n5.DISPLAY QUEUE A.\n6.DISPLAY QUEUE B.\n7.EXIT\n");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            insertA();
            break;
        case 2:
            insertB();
            break;
        case 3:
            deleteA();
            break;
        case 4:
            deleteB();
            break;
        case 5:
            displayA();
            break;
        case 6:
            displayB();
            break;
        case 7:
            break;
        }
    }while(option != 7);
    
    return 0;
}