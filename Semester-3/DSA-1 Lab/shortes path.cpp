#include<bits/stdc++.h>
using namespace std;
int visited[100];
int dis[100];
vector<int>adj[101];
int bfs(int s,int d){
    queue<int>q;
    q.push(s);
    visited[s]==1;
    while(q.size()!=0){
        int c=q.front();
        q.pop();
        for(int i=0;i<adj[c].size();i++){
            int b=adj[c][i];
            if(visited[b]==0){
                q.push(b);
                visited[b]==1;
                dis[b]=dis[c]+1;
            }
        }
    }
    return dis[d];
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    int source,des;
    cin>>source>>des;
    int count=0;

    cout<<bfs(source,des)<<endl;

}
