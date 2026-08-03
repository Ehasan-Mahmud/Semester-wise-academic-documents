#include<bits/stdc++.h>
using namespace std;
int visited[101];
vector<int> adj[101];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]==1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0; i<adj[x].size(); i++)
        {
            int f=adj[x][i];
            if(visited[f]==0)
            {
                q.push(f);
                visited[f]==1;
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int c=0;
    for(int i=0; i<n; i++)
    {
        if(visited[i]==0)
        {
            bfs(i);
            c++;
        }
    }
    cout<<c<<endl;


}
