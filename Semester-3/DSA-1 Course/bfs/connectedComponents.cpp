#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int visited[N];
vector<int>adj[N];

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=1;

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
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            bfs(i);
            c++;
        }
    }
    cout<<c<<endl;

    return 0;
}

/*
5 2
0 1
2 4
*/
