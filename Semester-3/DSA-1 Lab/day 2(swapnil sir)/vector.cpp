#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<string> v, w;
    v.push_back("Shukhen");
    v.push_back("Deb");
    v.push_back("Nowrin");
    v.push_back("Al Amin");
    v.push_back("Aupo");
    v.push_back("Sarafat");

    int n = v.size();
    cout<<"Size: "<<n<<endl;

    sort(v.begin(), v.end());
    for(int i=0; i<n; i++)  cout<<v[i]<<endl;

    v.clear();
    cout<<v.size();

    return 0;
}
