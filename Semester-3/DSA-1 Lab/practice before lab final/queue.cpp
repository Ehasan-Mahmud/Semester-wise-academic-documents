#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<string>q;
    q.push("E");
    q.push("H");
    q.push("A");
    q.push("S");
    q.push("A");
    q.push("N");
    while(q.size()){
        cout<<q.front()<<" "<<endl;
        q.pop();
    }


}
