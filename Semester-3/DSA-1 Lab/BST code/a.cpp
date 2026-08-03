#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node *left,*right,*parent;
    Node(int x){                       ///contructor
        key=x;
        left=right=parent=NULL;
    }
       };
struct BST{
    Node *root;
    BST(){
        root=NULL;
    }

    void insert(int x){
            Node *tmp=new Node(x);
            if(root==NULL){
                root=tmp;
                return;
            }
            Node *fast=root,*slow=NULL;
            while(fast!=NULL){
                slow=fast;
                if(x<fast->key) fast=fast->left;
                else fast=fast->right;
            }
            if(x<slow->key) {
                slow->left=tmp;}
            else {slow->right=tmp;}
                tmp->parent=slow;
            }

    void inorder(Node *tmp){
        if(tmp==NULL) return;
        inorder (tmp->left);
        cout<<tmp->key<<" ";
        inorder(tmp->right);
    }
    int maximum(Node *tmp){
        //if(root==NULL) return;
        if(tmp->right==NULL) return tmp->key;
        return maximum(tmp->right);
        //cout<<tmp->key<<endl;
    }
    int height(Node *tmp){
        if(tmp==NULL) return -1;
        return 1+max(height(tmp->left),height(tmp->right)); ///max fun. use na krte chaile value x,y e rekhe if/else dye compare krlei hbe
    }

};
int main(){
    int choice;
    BST b;          ///bahire karon ektar tree tei sob krbo,tai BST er obj. bahire create kra lgbe;
    while(1){
        cout<<"Insert choice :";
        cin>>choice;
        if(choice ==1){  ///insert
            cout<<"Insert value :";
            int x;
            cin>>x;
            b.insert(x);
        }
        else if(choice==2){
            cout<<"Sorted :";
            b.inorder(b.root);  ///BST class er mdde root,tai BST cls er obj. call kre pass korate hbe.
        }
        cout<<endl<<endl;
    }

}
/* 1 ///choice
44 17 88 32 65 97 28 54 82 29 76 80
*/
