#include <bits/stdc++.h>
using namespace std;
int BFS(int Src,int target,int n,vector<int>& parent,vector<vector<int>>& graph){
    fill(parent.begin(),parent.end(),-1);
    parent[Src] = -2;
    queue<pair<int,int>> q;
    q.push({Src,1e9});
    while(!q.empty()){
        int u = q.front().first, cap = q.front().second;
        q.pop();
        for(int v=0;v<n;v++){
            if(u!=v && graph[u][v]!=0 && parent[v]==-1){
                parent[v] = u;
                int min_cap = min(cap,graph[u][v]);
                if(v==target)return min_cap;
                q.push({v,min_cap});
            }
        }
    }
    return 0;
}
int f_Fulker(int source,int target,int n,vector<vector<int>>& graph){
    vector<int> parent(n,-1);
    int max_flow = 0,min_cap = 0;
    while(min_cap = BFS(source,target,n,parent,graph)){
        max_flow += min_cap;
        int v = target;
        while(v!=source){
            int u = parent[v];
            graph[u][v] -= min_cap;
            graph[v][u] += min_cap;
            v=u;
        }
    }
    return max_flow;
}
void addEdge(vector<vector<int>>& graph,int u,int v,int w){
    graph[u][v] = w;
}
int main(){
    int V = 6;
    vector<vector<int>> graph(V,vector<int>(V,0));
    addEdge(graph,0,1,4);
    addEdge(graph,0,3,3);
    addEdge(graph,1,2,4);
    addEdge(graph,2,3,3);
    addEdge(graph,2,5,2);
    addEdge(graph,3,4,6);
    addEdge(graph,4,5,6);
    cout << "Max Flow: " << f_Fulker(0,5,V,graph) << endl;
    return 0;
}

