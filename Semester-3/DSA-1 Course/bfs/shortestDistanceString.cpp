#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int visited[N];
int dis[N];
int par[N+1];
vector<int>adj[N];
map<string,int>c;
int cnt=1;
map<int,string>rev_c;

void pathfinder(int s,int t)
{
    if(par[t]==-1) {
        cout<<rev_c[t]<<" ";
        return;
    }

    pathfinder(s,par[t]);
    cout<<rev_c[t]<<" ";

}

int bfs(int s,int t)
{
    queue<int>q;
    q.push(s);
    visited[s]=1;
    dis[s]=0;
    par[s]=-1;

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
                par[v]=u;
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
        string us,vs;
        cin>>us>>vs;
        int u,v;
        if(c[us]==0){
            c[us]=cnt++;
        }
        if(c[vs]==0){
            c[vs]=cnt++;
        }
        u=c[us];
        v=c[vs];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(auto i:c)
    {
        rev_c[i.second]=i.first;     /// map c is having DAC-0,SYL-1 etc. map rev_c will have 0-DAC ,1-SYL
    }
    int source,target;
    string ss,ts;
    cout<<"Enter Source : ";
    cin>>ss;
    cout<<"Enter Target : ";
    cin>>ts;
    source=c[ss];
    target=c[ts];
    cout<<bfs(source,target)<<endl;
    pathfinder(source,target);

    return 0;
}

/*
5 5
DAC SYL
DAC CTG
SYL RJH
CTG BGR
RJH BGR
*/

