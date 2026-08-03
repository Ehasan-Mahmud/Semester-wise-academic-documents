#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int flag=0;
    int count=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='b') flag=1;
        if(s[i]!='a' && s[i]!='b'){
            count=1;
            break;
        }
    }
    if(flag==1 && count==0) cout<<"Valid String"<<endl;
    else if(count==1) cout<<"Invalid String"<<endl;
    else if(flag==0) cout<<"Invalid String"<<endl;
}
