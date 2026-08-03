#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int>adj[N];
int visited[N];
int dis[N];

void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=1;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                q.push(v);
                visited[v]=1;
            }
        }
    }
}

int main(){

    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(0);

    return 0;
}

/*
6 7
0 1
0 2
0 3
0 4
1 3
4 5
2 5
*/
