#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node *left,*right,*parent;
    Node(int x){
        key=x;
        left=right=parent=NULL;
    }
};
struct BST{
    int len;
    Node *root;
    BST(){
        root==NULL;
        len=0;
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
            if(x<fast->key){
                fast=fast->left;
            }
            else fast=fast->right;
        }
        if(x<slow->key){
            slow->left=tmp;
        }
        else slow->right=tmp;
        tmp->parent=slow;
        len++;
    }
    void inorder(Node *tmp){
        if(tmp==NULL) return;
        inorder(tmp->left);
        cout<<tmp->key<<" ";
        inorder(tmp->right);
    }
    int maximum(Node *tmp){
        if(tmp->right==NULL) return tmp->key;
        return maximum(tmp->right);

    }
    int height(Node *tmp){
        if(tmp==NULL) return 0;
        return 1+ max(height(tmp->left),height(tmp->right));
    }
    int Size(Node *tmp){
        if(tmp==NULL) return 0;
        return 1+Size(tmp->left)+Size(tmp->right);
    }
    int minimum(Node *tmp){
        if(tmp->left==NULL) return tmp->key;
        return minimum(tmp->right);

    }
    Node *find(int x,Node *tmp){
        if(tmp==NULL) return tmp;
        else if(tmp->key==x) return tmp;
        if(x<tmp->key) return find(x,tmp->left);
        return find(x,tmp->right);

    }
    bool delete0child(Node *tmp){
        if(tmp==root){
            delete tmp;
            root=NULL;
        }
        Node *par=tmp->parent;
        if(tmp->key < par->key) par->right=NULL;
        else tmp->left=NULL;
        delete tmp;
        return true;

    }
    bool delete1child(Node *tmp){
        if(tmp==root){
           Node *child=tmp->right;
           if(child==NULL) child=tmp->left;
           delete tmp;
           root=child;
        }
        Node *par=tmp->parent;
        Node *child=tmp->left;
        if(child==NULL){
            child=tmp->right;
        }
        if(par->key < tmp->key){
            par->right=child;
        }
        else par->left=child;
        delete tmp;
        child->parent=par;
    }
    Node *findios(Node *tmp){
        if(tmp->left==NULL) return tmp;
        findios(tmp->left);
    }
    bool delete2child(Node *tmp){
        Node *par=tmp->parent;
        Node *ios=findios(tmp->right);
        tmp->key=ios->key;
        if(ios->right==NULL) {
            delete0child(ios);
        }
        else {
            delete1child(ios);
        }
        return true;
    }
    bool deletenode(Node *tmp){
        if(tmp->left==NULL && tmp->right==NULL){
            delete0child(tmp);

        }
        else if(tmp->left!=NULL && tmp->right!=NULL){
            delete2child(tmp);
        }
        else{
            delete1child(tmp);
        }
    }



};
int main(){

    BST b;
    int x;
    cout<<"choice one:";
    cin>>x;
    if
}
