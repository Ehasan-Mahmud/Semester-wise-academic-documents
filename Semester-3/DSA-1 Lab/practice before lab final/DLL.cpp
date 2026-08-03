#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int v;
    Node *L,*R;
};
struct DLL
{
    Node *head;
    Node *tail;
    DLL(){
        head=NULL;
        tail=NULL;

    }
    void createFirstelement(int x)
    {
        Node *head=(Node*)malloc(sizeof(Node));
        head->v=x;
        head->L=NULL;
        head->R=NULL;
        //head=tmp;
        tail=head;
    }
    void insertFirst(int x)
    {
        if(head==NULL)
        {
            createFirstelement(x);
            return;
        }
        Node *tmp=(Node*)malloc(sizeof(Node));
        tmp->v=x;
        tmp->R=head;
        head->L=tmp;
        head->L=NULL;
        if(tail==NULL)
        {
            tail=head;
        }
    }
    void insertLast(int x)
    {
        if(tail==NULL)
        {
            createFirstelement(x);
        }
        Node *tmp=(Node*)malloc(sizeof(Node));
        tmp->v=x;
        tmp->R=NULL;
        tmp->L=tail;
        tail->R=tmp;
        tail=tmp;
        if(head==NULL)
        {
            head=tail;
        }
    }
    void traverse()
    {
        Node *tmp=head;
        while(tmp!=NULL)
        {
            cout<<tmp->v<<" ";
            tmp=tmp->R;
        }
    }
};

int main()
{
    DLL l;
    while(true)
    {
        int x;
        cin>>x;
        l.insertFirst(x);
        l.traverse();

    }

}
