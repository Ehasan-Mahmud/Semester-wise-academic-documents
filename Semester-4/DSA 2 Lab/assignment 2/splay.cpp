#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int value;
    TreeNode *leftChild,*rightChild;
};
TreeNode* createNode(int value)
{
    TreeNode* Node=new TreeNode();
    Node->value=value;
    Node->leftChild=Node->rightChild=NULL;
    return Node;
}
TreeNode* rotateRight(TreeNode *currentNode)
{
    TreeNode *leftNode=currentNode->leftChild;
    currentNode->leftChild=leftNode->rightChild;
    leftNode->rightChild=currentNode;
    return leftNode;
}
TreeNode* rotateLeft(TreeNode *currentNode)
{
    TreeNode *rightNode=currentNode->rightChild;
    currentNode->rightChild=rightNode->leftChild;
    rightNode->leftChild=currentNode;
    return rightNode;
}
TreeNode* splay(TreeNode *rootNode,int value)
{
    if(rootNode==NULL||rootNode->value==value)return rootNode;
    if(rootNode->value>value)
    {
        if(rootNode->leftChild==NULL)return rootNode;
        if(rootNode->leftChild->value>value)
        {
            rootNode->leftChild->leftChild=splay(rootNode->leftChild->leftChild,value);
            rootNode=rotateRight(rootNode);
        }
        else if(rootNode->leftChild->value<value)
        {
            rootNode->leftChild->rightChild=splay(rootNode->leftChild->rightChild,value);
            if(rootNode->leftChild->rightChild!=NULL)rootNode->leftChild=rotateLeft(rootNode->leftChild);
        }
        return(rootNode->leftChild==NULL)?rootNode:rotateRight(rootNode);
    }
    else
    {
        if(rootNode->rightChild==NULL)return rootNode;
        if(rootNode->rightChild->value>value)
        {
            rootNode->rightChild->leftChild=splay(rootNode->rightChild->leftChild,value);
            if(rootNode->rightChild->leftChild!=NULL)rootNode->rightChild=rotateRight(rootNode->rightChild);
        }
        else if(rootNode->rightChild->value<value)
        {
            rootNode->rightChild->rightChild=splay(rootNode->rightChild->rightChild,value);
            rootNode=rotateLeft(rootNode);
        }
        return(rootNode->rightChild==NULL)?rootNode:rotateLeft(rootNode);
    }
}
TreeNode* insertNode(TreeNode *rootNode,int newValue)
{
    if(rootNode==NULL)return createNode(newValue);
    rootNode=splay(rootNode,newValue);
    if(rootNode->value==newValue)return rootNode;
    TreeNode *newNode=createNode(newValue);
    if(rootNode->value>newValue)
    {
        newNode->rightChild=rootNode;
        newNode->leftChild=rootNode->leftChild;
        rootNode->leftChild=NULL;
    }
    else
    {
        newNode->leftChild=rootNode;
        newNode->rightChild=rootNode->rightChild;
        rootNode->rightChild=NULL;
    }
    return newNode;
}
void preOrderTraversal(TreeNode *rootNode)
{
    if(rootNode!=NULL)
    {
        cout<<rootNode->value<<" ";
        preOrderTraversal(rootNode->leftChild);
        preOrderTraversal(rootNode->rightChild);
    }
}
int main()
{
    TreeNode *rootNode=createNode(6);
    rootNode->leftChild=createNode(3);
    rootNode->rightChild=createNode(8);
    rootNode->leftChild->leftChild=createNode(50);
    rootNode->leftChild->leftChild->leftChild=createNode(40);
    rootNode->leftChild->leftChild->leftChild->leftChild=createNode(30);
    rootNode=insertNode(rootNode,25);
    cout<<"PreOrder traversal of the Splay tree:";
    cout<<endl;
    preOrderTraversal(rootNode);
    return 0;
}
