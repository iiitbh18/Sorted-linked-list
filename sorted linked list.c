#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *insert(struct node *start,int data);
void search(struct node *start,int data);
void display(struct node *start);
main()
{
    struct node *start=NULL;
    int choice,data;
    while(1)
    {
        printf("1.insert\n");
        printf("2.displsy\n");
        printf("3.search\n");
        printf("4.exit\n");
        printf("enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("enter the element to be inserted\n");
            scanf("%d",&data);
            start=insert(start,data);
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("enter the item to be searched");
            scanf("%d",&data);
            search(start,data);
            break;
        case 4:
            exit(1);
        default:
            printf("wrong choice\n");
        }
    }
}
void display(struct node *start)
{
    struct node *p;
    if(start==NULL)
    {
        printf("list is empty\n");
        return;
    }
    p=start;
    while(p!=NULL)
    {
        printf("%d",p->info);
        p=p->link;
    }
    printf("\n");
}
void search(struct node *start,int data)
{
    struct node *p;
    int pos=1;
    while(p!=NULL)
    {
        if(data==p->info)
        {
            printf("%d element found\n at %d position",data,pos);
            return;
        }
        p=p->link;
        pos++;
    }

    printf("%d element not found in the list\n");

}
struct node *insert(struct node *start,int data)
{
struct node *p,*temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->info=data;
if(start==NULL || data>start->info)
{
    temp->link=start;
    start=temp;
    return start;
}
else
{
p=start;
while(p->link!=NULL && p->link->info>data)
    p=p->link;
temp->link=p->link;
p->link=temp;
return start;
}

};





















