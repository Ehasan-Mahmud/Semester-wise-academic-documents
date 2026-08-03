#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
int main()
{
   int n,e;
   cin>>n>>e;
   int arr[n+1][n+1];
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        arr[i][j]=0;
    }
   }
   while(e--){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back(v);
    adj[v].push_back(u);
    arr[u][v]=w;
    arr[v][u]=w;
   }
   cout<<endl;
   cout<<endl;
   int m;
   cout<<"Enter the value for which adj. we want to know: "<<endl;
   cin>>m;
   for(int i=0;i< adj[m].size();i++){
        cout<<adj[m][i]<<" ";
   }
   cout<<endl;


}
/*
6 9
1 2 5
1 3 1
1 4 3
1 5 5
2 6 8
2 4 3
3 4 2
3 5 4
6 4 7
*/


