#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
const ll MOD=998244353;
const ll M=200005;
template<typename T>
using indexed_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
ll calculateMaxValue(vector<ll>&weights,vector<ll>&values,ll capacity)
{
 ll numItems=values.size();
 vector<ll>dynamicProgramming(capacity+1,0);
 for(ll i=0; i<numItems; i++)
 {
 for(ll j=capacity; j>=weights[i]; j--)
 {
 dynamicProgramming[j]=max(dynamicProgramming[j],values[i]+dynamicProgramming[j-weights[i]]);
 }
 }
 return dynamicProgramming[capacity];
}
void executeSolution()
{
 vector<ll>weights= {2,3,4,5};
 vector<ll>values= {3,4,5,6};

 ll maxCapacity=5;
 ll result=calculateMaxValue(weights,values,maxCapacity);
 cout<<"The maximum value achievable is: "<<result<<endl;
}
int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);
 executeSolution();
 return 0;
}
