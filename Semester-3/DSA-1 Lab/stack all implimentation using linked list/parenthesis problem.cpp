#include<bits/stdc++.h>
using namespace std;
int main()
{
    int flag=0;
    stack<char>st;
    string s;
    cin>>s;

    for (int i=0; i<s.size(); i++)
    {
        char c=s[i];
        if(c=='('||c=='{'||c =='[')
        {
            st.push(c);             // opening bracket thklei stack e push krbo
        }
        else if(c==')'||c=='}'||c==']')   // closing bracket paile ()/{}/[] matching holei pop krbo top element, matching na hoile unbalanced
        {
            if(st.size()==0)  // stack jdi already NULL thke tahole pop krte parbo na mane unbalanced, tai closing bracket pailei pop korar age check kre nicci stack ki NULL kina
            {
                flag=1;
                break;
            }
            else if(c==')' && st.top()=='(')   // () erkm matching dekhbo jdi matching hy tahole '(' bracket ta pop kre felbo
            {
                st.pop();
            }
            else if(c=='}' && st.top()=='{')    // {} erkm matching dekhbo jdi matching hy tahole '{' bracket ta pop kre felbo
            {
                st.pop();
            }
            else if(c==']' && st.top()=='[')    // [] erkm matching dekhbo jdi matching hy tahole '[' bracket ta pop kre felbo
            {
                st.pop();
            }
            else
            {
                flag=1;
                break;
            }
        }
        else
        {
            flag=1;
            break;
        }
    }
    if(flag==1 || st.size()!=0)        // jdi balanced thke tahole pop krte krte stack e NULL hye jabe oporer loop seshe,,, r jdi NULL na hy tarmane unbalanced
    {
        cout << "unbalanced" << endl;
    }
    else
    {
        cout << "Balanced" << endl;
    }
    /*if(st.size()!=0)      // unbalanced thkle ki ki element ache stack e ekhno, seigula print krte parbo
    {
        for(int i=0; i<st.size(); i++)
        {
            cout << st.top();
            st.pop();

        }
    }*/
    return 0;
}

/*
{[}
{[(])}
{[()]}
{()()[]{}}
*/
