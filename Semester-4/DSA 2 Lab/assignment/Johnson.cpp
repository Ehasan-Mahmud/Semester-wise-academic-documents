#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18;
const int NN=500;
vector<pair<int,int>>G[NN];
vector<int>Bell_f(int N,vector<vector<int>>&edges){
    vector<int>r(N+1,INF);
    r[0]=0;
    for(int i=0;i<=N;i++){
        bool check=false;
        for(auto&e:edges){
            int u=e[0],v=e[1],w=e[2];
            if(r[u]!=INF&&r[v]>r[u]+w){
                r[v]=r[u]+w;
                check=true;
            }
        }
        if(!check)break;
    }
    return r;
}
void Dijk(int src,vector<vector<int>>&path,int N){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(N+1,INF);
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int d=pq.top().first,u=pq.top().second;
        pq.pop();
        if(d>dist[u])continue;
        for(auto&[v,w]:G[u]){
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    path[src]=dist;
}
signed main(){
    int N,M;
    cin>>N>>M;
    vector<vector<int>>edges;
    for(int i=0;i<M;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    for(int i=1;i<=N;i++){
        edges.push_back({0,i,0});
    }
    vector<int>C=Bell_f(N,edges);
    for(auto&e:edges){
        e[2]+=(C[e[0]]-C[e[1]]);
    }
    for(auto&e:edges){
        if(e[0]!=0){
            G[e[0]].push_back({e[1],e[2]});
        }
    }
    vector<vector<int>>path(N+1,vector<int>(N+1,INF));
    for(int i=1;i<=N;i++){
        Dijk(i,path,N);
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(path[i][j]==INF){
                cout<<-1<<" ";
            }else{
                cout<<path[i][j]-(C[i]-C[j])<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
/*
4 5
1 2 3
1 3 8
1 4 -4
2 4 7
3 2 4
*/
