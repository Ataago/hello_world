//Doubly Linked List
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *prev, *next;
};
typedef struct node *Node;
Node First = NULL;

void InsertBeg();
void InsertEnd();
void InsertKey();
void DeleteBeg();
void DeleteEnd();
void DeleteKey();
void Display();

void main()
{
    int ch;

    printf("Enter Choice");
    while(1)
    {
        printf("\n\n1-InsertBeg 2-InsertEnd 3-InsertKey 4-DeleteBeg 5-DeleteEnd 6-DeleteKey 7-Display 0-Exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                InsertBeg();
                break;
            case 2:
                InsertEnd();
                break;
            case 3:
           //     InsertKey();
                break;
            case 7:
                Display();
                break;
            case 5:
                DeleteEnd();
                break;
            case 4:
                DeleteBeg();
                break;
            case 6:
              //  DeleteKey();
                break;
            case 0:
                printf("Exit");
                exit(0);
                break;
            default:
                printf("Invalid");
                break;
        }
    }
}
void InsertBeg()
{
    Node temp;
    temp = (Node)malloc(sizeof(Node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("Enter Element: ");
    scanf("%d",&temp->data);

    if(First)
    {
        temp->next = First;
        First->prev = temp;
    }
    First = temp;
}
void InsertEnd()
{
    Node cur, temp;
    temp = (Node)malloc(sizeof(Node));
    printf("Enter Element: ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    temp->prev = NULL;

    if(!First)
    {
        First = temp;
        return;
    }
    cur = First;
    while(cur->next)
        cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
}
void DeleteBeg()
{
    if(!First)
    {
        printf("Underflow");
        return;
    }
    Node cur = First;
    printf("Deleted %d",cur->data);
    if(!cur->next)
    {
        First = NULL;
        free(cur);
        return;
    }
    cur->next->prev = NULL;
    First = cur->next;
    free(cur);
}
void DeleteEnd()
{
    Node cur = First;
    if(!First)
    {
        printf("Underflow");
        return;
    }
    if(!cur->next)
    {
        printf("Deleted %d",cur->data);
        First = NULL;
        free(cur);
        return;
    }
    while(cur->next->next)
        cur = cur->next;
    printf("Deleted %d",cur->next->data);
    free(cur->next);
    cur->next = NULL;
}
void Display()
{
    if(!First)
    {
        printf("Underflow");
        return;
    }
    Node cur=First;
    while(cur->next)
    {
         printf("%d ",cur->data);
         cur = cur->next;
    }
    printf("%d",cur->data);
}
