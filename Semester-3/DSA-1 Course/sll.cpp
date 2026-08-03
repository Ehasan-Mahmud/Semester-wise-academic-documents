#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *next;
};

Node *head, *tail;

void init(){
    head = NULL;
    tail = NULL;
}
void insertFirst(int x){
    Node*tmp=(Node*)malloc(sizeof(Node));
    tmp->key=x;
    tmp->next=head;
    head=tmp;
    if(tail==NULL)
    {
        tail=head;
    }
}

void insertLast(int x){
    Node *tmp=(Node*)malloc(sizeof(Node));
    tmp->key=x;
    if(tail!=NULL) tail->next=tmp;
    tmp->next=NULL;
    tail=tmp;
    if(head==NULL)
    {
        head=tail;
    }
}

Node* find(int x){
    Node *tmp=head;
    while(tmp!=NULL)
    {
        if(tmp->key==x) return tmp;
        tmp=tmp->next;
    }
    return tmp;

}

bool deleteFirst(){
    if(head==NULL) return false;
    Node *tmp=head;
    head=head->next;
    free(tmp);
    if(head==NULL) tail=head;
    return true;


}

bool deleteLast(){
    if(!tail) return false;
    Node *slow=NULL,*fast=head;
    while(fast!=tail)
    {
        ///if(tail==NULL) return;
        slow=fast;
        fast=fast->next;
    }
    tail=slow;
    free(fast);
    tail->next=NULL;
    if(tail==NULL) head=NULL;
    return true;

}

bool deleteAny(int x){
    if(find(x)==NULL) return false;
    if(head->key==x) return deleteFirst();
    if(tail->key==x) return deleteLast();
    Node *slow=NULL;
    Node *fast=head;
    while(fast->key!=x)
    {
        slow=fast;
        fast=fast->next;
    }
    slow->next=fast->next;
    free(fast);
    return true;

}

void print( ){
    Node *tmp=head;
    while(tmp!=NULL)
    {
        cout<<tmp->key<<" ";
        tmp=tmp->next;
    }

}
bool sortB(){
    if(head==NULL||tail==NULL){
        return false;
    }
    Node *slow=head,*fast=head;
    for(fast=head;fast!=NULL;fast=fast->next){
        for(slow=head;slow!=NULL;slow=slow->next){
            if((slow->key)>(fast->key)){
                int tmp=slow->key;
                slow->key=fast->key;
                fast->key=tmp;
            }
        }
    }
    return true;

}
int Size(){
    int n=0;
    Node *tmp=head;
    for(tmp=head;tmp!=NULL;tmp=tmp->next){
        n++;
    }
    return n;

}
int mid(){
    int p=Size();
    if(p%2==0) cout<<"There is no mid value because it's size even number.\n";
    else{
        Node *slow=head,*fast=head;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            fast=fast->next;
        }
        return slow->key;
    }
}
bool dupli(){
    if(head==NULL||tail==NULL){
        return false;
    }
    Node *slow=head,*fast=head;
    int t=0;
    for(slow=head;slow!=NULL;slow=slow->next){
        for(fast=slow->next;fast!=NULL;fast=fast->next){
            if(slow->key==fast->key){
             t= deleteAny(fast->key)  ;
            }
        }
    }
    return t;
}
void insertbefore(int x,int y){ ///x will be set before y
    Node *slow=NULL,*fast=head;
   // if(find(y)==NULL) return;
    if(find(y)==head){
        insertFirst(x);
    }
    while(fast->key!=y){
        if(fast==NULL) return;
        slow=slow->next;
        fast=fast->next;
    }
    Node *tmp=(Node*)malloc(sizeof(Node));
    tmp->key =x;
    slow->next=tmp;
    tmp->next=fast;

        }
void insertafter(int x,int y){///x will be set after y
    Node *slow=NULL,*fast=head;
   // if(find(y)==NULL) return;
    if(find(y)==tail){
        insertLast(x);
    }
    while(fast->key!=y){
        if(fast==NULL) return;
        slow=fast;
        fast=fast->next;
    }
    Node *tmp=(Node*)malloc(sizeof(Node));
    tmp->key =x;
    tail->next=tmp;
    tmp->next=NULL;
    tail=tmp;
        }
void reverseprint(){
    Node *tmp=head;
    if(tmp==NULL) return;
    tmp=tmp->next;
    reverseprint();
    cout<<tmp->key<<" ";

}


int main(){
    init();
    cout<<"1. Insert First           2. Insert last             3. Find\n";
    cout<<"4. Delete First           5. Delete last             6. Delete Any\n";
    cout<<"7. Print                  8. To be implemented       9. To be implemented\n";
    cout<<"10. To be implemented     10. To be implemented      11. To be implemented\n";

    while(1){

        int choice;   cin>>choice;

        if(choice==1){
            cout<<"Enter value: ";
            int x;   cin>>x;   insertFirst(x);
            cout<<x<<" has been inserted at first"<<endl<<endl;
        }

        else if(choice==2){
            cout<<"Enter value: ";
            int x;   cin>>x;   insertLast(x);
            cout<<x<<" has been inserted at last"<<endl<<endl;
        }

        else if(choice==3){
            cout<<"Enter value: ";
            int x;   cin>>x;   Node *temp = find(x);
            if(temp == NULL) cout<<x<<" has not been found"<<endl<<endl;
            else cout<<x<<" has been found"<<endl<<endl;
        }

        else if(choice==4){
            bool status = deleteFirst();
            if(status == false) cout<<"No element in the list"<<endl<<endl;
            else cout<<"First element has been deleted successfully"<<endl<<endl;
        }

        else if(choice==5){
            bool status = deleteLast();
            if(status == false) cout<<"No element in the list"<<endl<<endl;
            else cout<<"Last element has been deleted successfully"<<endl<<endl;
        }

        else if(choice==6){
            cout<<"Enter value: ";
            int x;   cin>>x;   bool status = deleteAny(x);
            if(status == false) cout<<x<<" could not be deleted"<<endl<<endl;
            else cout<<x<<" has been deleted successfully"<<endl<<endl;
        }

        else if(choice==7){
            cout<<"The list is: ";    print();   cout<<endl<<endl;
        }

        else if(choice==8){

        }

        else if(choice==9){

        }

        else if(choice==10){

        }

        else if(choice==11){

        }

        else if(choice==12){

        }

        else {
            cout<<"Invalid choice"<<endl<<endl;
        }
    }
}
