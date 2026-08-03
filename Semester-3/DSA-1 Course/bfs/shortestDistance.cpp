#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int visited[N];
int dis[N];
vector<int>adj[N];

int bfs(int s,int t)
{
    queue<int>q;
    q.push(s);
    visited[s]=1;
    dis[s]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(visited[v]==0)
            {
                q.push(v);
                visited[v]=1;
                dis[v]=dis[u]+1;
            }
        }
    }
    return dis[t];
}


int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int source,target;
    cout<<"Enter Source : ";
    cin>>source;
    cout<<"Enter Target : ";
    cin>>target;
    cout<<bfs(source,target);
    return 0;
}

/*
5 5
0 1
0 2
1 3
3 4
4 2
*/
