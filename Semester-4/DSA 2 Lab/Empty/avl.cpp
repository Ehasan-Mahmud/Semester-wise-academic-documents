#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};
int height(Node *n)
{
    return n ? n->height:0;
}
int max(int a,int b)
{
    return (a>b) ? a:b;
}
Node* newNode(int key)
{
    Node* node=new Node();
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
}

Node* rightRotate(Node *y)
{
    Node *x=y->left;
    Node *T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}
Node* leftRotate(Node *x)
{
    Node *y=x->right;
    Node *T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=max(height(x->left),height(x->right))+1;
    y->height= max(height(y->left),height(y->right))+1;
    return y;
}
int getBalance(Node *n)
{
    return n ? height(n->left)-height(n->right):0;
}
Node* insert(Node* node,int key)
{
    if (!node)
        return newNode(key);
    if (key<node->key)
        node->left=insert(node->left,key);
    else if (key>node->key)
        node->right=insert(node->right,key);
    else
        return node;
    node->height=1+max(height(node->left),height(node->right));
    int balance=getBalance(node);
    if (balance>1 && key<node->left->key)
        return rightRotate(node);
    if (balance<-1 && key>node->right->key)
        return leftRotate(node);
    if (balance>1 && key>node->left->key)
    {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance<-1 && key<node->right->key)
    {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void preOrder(Node *root)
{
    if (root!=NULL)
    {
        cout<<root->key<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
Node* minValueNode(Node* node)
{
    Node* current=node;
    while(current->left)
        current=current->left;
    return current;
}
Node* deleteNode(Node* root,int key)
{
    if (!root)
        return root;
    if (key<root->key)
        root->left=deleteNode(root->left,key);
    else if (key>root->key)
        root->right=deleteNode(root->right,key);
    else
    {
        if (!root->left || !root->right)
        {
            Node* temp=root->left ? root->left:root->right;
            if (!temp)
            {
                temp=root;
                root=NULL;
            }
            else
                *root=*temp;
            delete temp;
        }
        else
        {
            Node* temp=minValueNode(root->right);
            root->key=temp->key;
            root->right=deleteNode(root->right,temp->key);
        }
    }
    if (!root)
        return root;
    root->height=1+max(height(root->left),height(root->right));
    int balance=getBalance(root);
    if (balance>1 && getBalance(root->left)>=0)
        return rightRotate(root);
    if (balance>1 && getBalance(root->left)<0)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance<-1 && getBalance(root->right)<=0)
        return leftRotate(root);
    if (balance<-1 && getBalance(root->right)>0)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
int main()
{
    Node *root=NULL;
    for (int i=1; i<=8; ++i)
        root=insert(root,i);
    cout << "AVL tree:"<<endl;
    preOrder(root);
    cout << endl;
    Node *rootLL = rightRotate(root);
    cout<<endl;
    cout << "After LL rotation on root:"<<endl;
    preOrder(rootLL);
    cout<<endl;
    root=NULL;
    for (int i=1; i<=8; ++i)
        root=insert(root,i);
    Node *rootRR=leftRotate(root);
    cout<<endl;
    cout<<"After RR rotation on root:"<<endl;
    preOrder(rootRR);
    cout<<endl;

    root=NULL;
    for (int i=1; i<=8; ++i)
        root=insert(root,i);
    root->left=leftRotate(root->left);
    Node *rootLR=rightRotate(root);
    cout<<endl;
    cout << "After LR rotation on root:"<<endl;
    preOrder(rootLR);
    cout<<endl;
    root=NULL;
    for (int i=1; i<=8; ++i)
        root=insert(root,i);
    root->right=rightRotate(root->right);
    Node *rootRL=leftRotate(root);
    cout<<endl;
    cout<<"After RL rotation on root:"<<endl;
    preOrder(rootRL);
    cout<<endl;
    root=NULL;
    for (int i=1; i<=8; ++i)
        root=insert(root,i);
    cout<<endl;
    cout<<"Before Delete 5 :"<<endl;
    preOrder(root);
    cout<<endl;
    root=deleteNode(root,5);
    cout<<endl;
    cout<<"After Delete 5 and Rebalancing:"<<endl;
    preOrder(root);
    return 0;
}
