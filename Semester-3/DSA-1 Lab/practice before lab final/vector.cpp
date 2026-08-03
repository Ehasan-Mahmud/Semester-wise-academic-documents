#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>vt;
    int x=1;
    while(x!=0){
        cin>>x;
        vt.push_back(x);
    }
    cout<<"Size of the Vector:"<<vt.size()<<endl;
    for(int i=0;i<vt.size();i++){
        cout<<vt[i]<<" ";
    }
}
