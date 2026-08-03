#include<iostream>
#include<map>
using namespace std;

int main(){
    map<float, string> m;
    m[3.5] = "Raihan";
    m[2.2] = "Sarafat";
    m[2.5] = "Aupo";
    m[3.6] = "Deb";




    map<float, string>::iterator p;
    for(p=m.begin(); p!=m.end(); p++){
        ///cout<<p->first<<" "<<p->second<<endl;
        float index = p->first;
        cout<<index<<" "<<m[index]<<endl;
    }






    ///cout<<m[2.5];
    return 0;
}
