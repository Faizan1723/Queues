#include<stdio.h>
#include<stdlib.h>
struct node
{
    int player_id;
    struct node* link;
}*start,*ptr,*newnode;

int main()
{
    int n;
    int k;
    printf("ENTER THE NO. OF PLAYERS: ");
    scanf("%d",&n);

    printf("\nENTER THE VALUE OF K (SO THAT EVERY Kth PLAYER GETS ELEMINATED): ");
    scanf("%d",&k);

    start=malloc(sizeof(struct node));
    start->player_id=1;
    ptr=start;

    for(int i=2;i<=n;i++)
    {
        newnode=malloc(sizeof(struct node));
        ptr->link=newnode;
        newnode->player_id=i;
        newnode->link=start;
        ptr=newnode;
    }

    for(int i=n;i>1;i--)
    {
        for(int j=0;j<k-1;j++)
        {
            ptr=ptr->link;
        }
        ptr->link=ptr->link->link;
    }

    printf("\nTHE WINNER IS THE PLAYER %d",ptr->player_id);
    return 0;
}