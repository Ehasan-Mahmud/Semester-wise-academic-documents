#include<bits/stdc++.h>
using namespace std;
int visited[101];
vector<int>adj[101];
int dis[101];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i];
            if(visited[v]==0){
                q.push(v);
                visited[v]=1;

            }
            //cout << "2";
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int c=0;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            bfs(i);
            c++;
        }
    }
    cout<<c<<endl;

}
/*
6 4
1 2
2 3
3 4
5 6
*/

