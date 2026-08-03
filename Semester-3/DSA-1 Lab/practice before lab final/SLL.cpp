#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node *next;

};
struct DLL{
    Node *head=NULL;
    Node *tail=NULL;
};

void insertFirst(int x){
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->key=x;
    temp->next=head;
    head=temp;
    if(tail==NULL){
        tail=head;
    }
}
void insertLast(int x){
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->key=x;
    if(tail!=NULL){
        tail->next=temp;
    }
    temp->next=NULL;
    tail=temp;
    if(head==NULL){
        head=temp;
    }
}
void traverse(){
    Node *L=head;
    while(L!=NULL){
        cout<<L->key<<" ";
        L=L->next;

    }
}
Node *find(int x){
    Node *temp=head;
    while(temp!=NULL){
        if(temp->key==x){
            return temp;
        }
        temp=temp->next;
    }
    return temp;
}

bool deleteFirst(){
    if(head==NULL) return false;
    Node *temp=head;
    head=head->next;
    free(temp);
    if(head==NULL){
        tail=head;
    }
    return true;
}
bool deleteLast()
{
    if(tail==NULL){
        return false;
    }
    Node *first=head;
    Node *last=NULL;
    while(first==tail){
        last=last->next;
        first=first->next;
    }
    tail=last;
    free(first);
    tail->next=NULL;
    if(tail==NULL){
        head=tail;
    }
    return true;

}
bool deleteAny(int x){
    if(find(x)==NULL) return false;
    if(head->key==x) deleteFirst();
    if(tail->key==x) deleteLast();
    Node *fast=head;
    Node *slow=NULL;
    while(fast->key!=x){
        slow=fast;
        fast=fast->next;
    }
    slow->next=fast->next;
    free(fast);
    return true;
}
int main()
{
    while(true){
        int x;
        cin>>x;
        insertFirst(x);
        //insertLast(x);
        traverse();
    }

}
