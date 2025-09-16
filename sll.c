#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *newnode;
struct node *temp;
struct node *prevnode;
struct node *createnode()
{
    printf("Enter element to be inserted:-\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    return newnode;
}
void begininsert()
{
    newnode=createnode();
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void display()
{
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("| %d |->",temp->data);
            temp=temp->next;
        }
    }
}
void endinsert()
{
    newnode=createnode();
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
}
void locationinsert()
{
    newnode=createnode();
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        int location;
        printf("Enter location at which element to be inserted:-\n");
        scanf("%d",&location);
        if(location==1)
        {
            newnode->next=head;
            head=newnode;
        }
        else
        {
            temp=head;
            for(int i=1;i<location-1;i++)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}
void begindelete()
{
    printf("\n%ld",sizeof(struct node));
    if(head==NULL)
        printf("Underflow\n");
    else
    {
        temp=head;
        if(head->next==NULL)
        {
            printf("Node deleted=%d\n",temp->data);
            head=head->next;
            free(temp);
        }
        else
        {
            
            head=head->next;
            printf("Node deleted=%d\n",temp->data);
            free(temp);

        }
    }
}
void enddelete()
{
    if(head==NULL)
        printf("Underflow\n");
    else
    {
        temp=head;
        if(head->next==NULL)
        {
            printf("Node deleted=%d\n",temp->data);
            head=head->next;
            free(temp);
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                prevnode=temp;
                temp=temp->next;
            }
            printf("Node deleted=%d\n",temp->data);
            prevnode->next=NULL;
            free(temp);
        }
    }
}
void locationdelete()
{
    if(head==NULL)
        printf("Underflow\n");
    else
    {
        if(head->next==NULL)
        {
            printf("Node deleted=%d\n",head->data);
            head=head->next;
            free(head);
        }
        else
        {
            int location;
            printf("Enter location from which value has to be deleted:-\n");
            scanf("%d",&location);
            if(location==1)
            {
                if(head->next==NULL)
                {
                    printf("Node deleted=%d\n",head->data);
                    head=head->next;
                    free(head);
                }
                else
                {
                    temp=head;
                    head=head->next;
                    printf("Node deleted=%d\n",temp->data);
                    free(temp);
                }
            }
            else
            {
                temp=head;
                for(int i=1;i<location;i++)
                {
                    prevnode=temp;
                    temp=temp->next;
                }
                printf("Node deleted=%d\n",temp->data);
                prevnode->next=temp->next;
                free(temp);
            }
        }
    }
}
void main()
{
    int choice;
    do
    {
        printf("\n1.Begin insert\n2.End insert\n3.Location insert\n4.Begin delete\n5.End delete\n6.Location delete\n7.Display\n8.Exit");
        printf("\nEnter your choice:-");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:begininsert();
            break;

            case 2:endinsert();
            break;

            case 3:locationinsert();
            break;

            case 4:begindelete();
            break;

            case 5:enddelete();
            break;

            case 6:locationdelete();
            break;

            case 7:display();
            break;
            
            case 8:printf("\nEXIT");
            break;
        }
    } while(choice!=8);    
}