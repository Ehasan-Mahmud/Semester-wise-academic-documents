#include<bits/stdc++.h>
#define infinite 10e9
#define maxx 10
using namespace std;
int Graph[maxx][maxx]={
   {0, 19, 8},
   {21, 0, 13},
   {15, 18, 0}
};
int DD[maxx][maxx],n;
int prims();
int main(){
   int i,j,cost;
   n=3;
   cost=prims();
   cout <<"Minimum Spanning Tree:";
   for(i=0;i<n;i++) {
      cout<<endl;
      for(j=0;j<n;j++)
         cout<<DD[i][j]<<" ";
   }
   cout<<endl;
   cout<<" Minimum cost= "<<cost;
   return 0;
}
int prims(){
   int C[maxx][maxx];
   int u,v,min_d,dist[maxx],from[maxx];
   int visited[maxx],ne,i,min_c,j;
   for(i=0;i<n;i++)
      for(j=0;j<n;j++) {
         if(Graph[i][j]==0)
            C[i][j]=infinite;
         else
            C[i][j]=Graph[i][j];
         DD[i][j]=0;
      }
   dist[0]=0;
   visited[0]=1;
   for(i=1;i<n;i++) {
      dist[i]=C[0][i];
      from[i]=0;
      visited[i]=0;
   }
   min_c=0;
   ne=n-1;
   while(ne>0) {
      min_d=infinite;
      for(i=1;i<n;i++)
         if(visited[i]==0&&dist[i]< min_d) {
            v = i;
            min_d=dist[i];
         }
      u=from[v];
      DD[u][v]=dist[v];
      DD[v][u]=dist[v];
      ne--;
      visited[v]=1;
      for(i=1;i<n;i++)
         if(visited[i]==0 && C[i][v]<dist[i]) {
            dist[i]=C[i][v];
            from[i]=v;
         }
      min_c=min_c+C[u][v];
   }
   return(min_c);
}
