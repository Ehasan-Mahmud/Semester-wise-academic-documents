#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *next;
};

struct Stack
{
    Node *top=NULL;
    int count=0;
    void creatFirst(int x)
    {
        Node *tmp=(Node*)malloc(sizeof(Node));
        tmp->key=x;
        tmp->next = nullptr;
        top=tmp;
        count++;
    }
    void push(int x)
    {
        if(count==0)
        {
            creatFirst(x);
            return;
        }
        Node *tmp=(Node*)malloc(sizeof(Node));
        tmp->key=x;
        tmp->next=top;
        top=tmp;
        count++;

    }
    int pop()
    {
        Node *tmp=(Node*)malloc(sizeof(Node));
        tmp=top;
        int popV = top->key;
        top=top->next;
        free(tmp);
        count--;
        return popV;
    }
    int size()
    {
        return count;
    }
    int topp()
    {
        if(count==0) return -1;
        return top->key;
    }
    bool isEmpty()
    {
        if(count==0) return true;
        return false;
    }
    void print()
    {
        Node *tmp=top;
        while(tmp!=NULL)
        {
            cout<<tmp->key<<" ";
            tmp=tmp->next;
        }
        cout<<endl;
    }


};
int main()
{
    Stack st;

    cout<<" 1.push\n 2.pop\n 3.top\n 4.Size\n 5.isEmpty\n 6.Print"<<endl;

    while(1)
    {
        cout<<"Choice one for implementation :\n";
        int n;
        cin>>n;
        if(n==1)
        {
            int x;
            cout<<"Enter the value of x:"<<endl;
            cin>>x;
            //cout<<"Enter the value of x for push:"<<endl;
            st.push(x);
            cout<<x<<" has beed pushed"<<endl;
        }
        else if(n==2)
        {
            if(st.size()==0) cout<<"Underflow"<<endl;
            else cout<<st.pop()<<" is poped"<<endl;;
        }
        else if(n==3)
        {
            if(st.topp()==-1) cout<<"Empty stack"<<endl;
            else cout<<st.topp()<<" is the top value"<<endl;
        }
        else if(n==4)
        {
            cout<<"Size is "<<st.size()<<endl;;
        }
        else if(n==5)
        {
            if(st.isEmpty()==true) cout<<"The stack is empty"<<endl;
            else cout<<"The stack is not empty"<<endl;
        }
        else if(n==6)
        {
            if(st.size()==0) cout<<"empty"<<endl;
            else st.print();
        }
    }

}


