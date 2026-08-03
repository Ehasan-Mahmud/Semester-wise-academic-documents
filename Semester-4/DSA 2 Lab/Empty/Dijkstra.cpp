#include<bits/stdc++.h>
using namespace std;
int min_dist(int Dis[], bool Vis[]){
   int Min=INT_MAX,id;
   for(int k=0; k<6; k++) {
      if(Vis[k]==false && Dis[k]<=Min) {
         Min=Dis[k];
         id=k;
      }
   }
   return id;
}
void G_dij(int graph[6][6],int src){
   int dist[6];
   bool visited[6];
   for(int k = 0; k<6; k++) {
      dist[k] = INT_MAX;
      visited[k] = false;
   }
   dist[src] = 0;
   for(int k = 0; k<6; k++) {
      int m=min_dist(dist,visited);
      visited[m]=true;
      for(int k = 0; k<6; k++) {
         if(!visited[k] && graph[m][k] && dist[m]!=INT_MAX && dist[m]+graph[m][k]<dist[k])
            dist[k]=dist[m]+graph[m][k];
      }
   }
   cout<<"Vertex  Distance from source"<<endl;
   for(int k = 0; k<6; k++) {
      char St=65+k;
      cout<<St<<"          "<<dist[k]<<endl;
   }
}
int main(){
   int graph[6][6]={
      {0, 1, 2, 0, 0, 0},
      {1, 0, 0, 5, 1, 0},
      {2, 0, 0, 2, 3, 0},
      {0, 5, 2, 0, 2, 2},
      {0, 1, 3, 2, 0, 1},
      {0, 0, 0, 2, 1, 0}
   };
   G_dij(graph,0);
   return 0;
}
