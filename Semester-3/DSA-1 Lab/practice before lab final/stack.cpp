#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int>st;
    for(int i=1;i<=5;i++){
        st.push(i);
    }
    while(st.top()!=-1){
        int x=st.top();
        cout<<x<<" ";
        st.pop();
        //top--;
    }

}
