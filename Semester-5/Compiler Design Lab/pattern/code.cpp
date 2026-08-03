#include<bits/stdc++.h>
using namespace std;
int main()
{

    string s;
    cin>>s;
    int n=s.size();
    int i=0;
    int flag=0;
    ///bool is_valid=true;
    if(s[i]=='a'){
        while(s[i]=='a'){
            i++;
        }
    }
    if(s[i]=='b'){
        while(s[i]=='b'){
            i++;
        }
    }
    else{
        flag =1;
        ///is_valid=false;
    }
    if(n != i){
        flag=1;
        ///is_valid=false;
    }

    /*
    if(is_valid){
        cout<<"Valid"<<endl;
    }
    else cout<<"invalid"<<endl;
    */
    if(flag==0){
        cout<<"Valid"<<endl;
    }
    else cout<<"invalid"<<endl;




}
