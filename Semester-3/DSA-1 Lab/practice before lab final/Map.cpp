#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,string>m;
    m[2]="H";
    m[1]="E";
    m[3]="A";
    m[6]="N";
    m[4]="S";
    m[5]="A";
    cout<<"Size :"<<m.size()<<endl;
    for(int i=1;i<=m.size();i++){
        cout<<m[i]<<" ";
    }

}
