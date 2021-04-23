#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node * prev;
    struct node * next;
};

void show(struct node* head)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void rev(struct node* head, struct node* tail)
{
    struct node* current, * nextnode;
    current=head;

    while(current!=NULL)
    {
        nextnode=current->next;
        current->next=current->prev;
        current->prev = current->next;
        current=nextnode;
    }
    current=head;
    head=tail;
    tail=current;
    cout<<"After Rev()-->";
    show(head);


}


void create()
{
    struct node* head, *tail, *newnode,*temp;
    int choice=1 ;

    while(choice)
    {
        newnode=(struct node *) malloc(sizeof(struct node));
        cout<<"ENTER : ";
        cin>>newnode->data;
        newnode->prev=NULL;
        newnode->next=NULL;

        if(head==NULL)
        {
            head=tail=newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        cout<<"0/1 ? : ";
        cin>>choice;
    }
    cout<<"Linked List created->";
    show(head);
    rev(head,tail);

}


int main()
{
    create();

    return 0;
}
