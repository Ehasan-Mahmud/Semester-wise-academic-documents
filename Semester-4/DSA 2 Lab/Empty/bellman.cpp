#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int source,dest,weight;
};
void Path(vector<int> const &parent,int v)
{
    if (v<0)
        return;
    Path(parent,parent[v]);
    cout <<v<<" ";
}
void Bell_f(vector<Edge> const &edges,int source,int N)
{
    int E=edges.size();
    vector<int>distance(N, INT_MAX);
    distance[source]=0;
    vector<int>parent(N,-1);
    int u,v,w,k=N;
    while(--k)
    {
        for(int j=0;j<E;j++)
        {
            u=edges[j].source,v=edges[j].dest;
            w=edges[j].weight;

            if(distance[u]!=INT_MAX && distance[u]+w<distance[v])
            {
                distance[v]=distance[u]+w;
                parent[v]=u;
            }
        }
    }
    for (int i=0;i<E;i++)
    {
        u=edges[i].source,v=edges[i].dest;
        w=edges[i].weight;

        if(distance[u]!=INT_MAX && distance[u]+w<distance[v])
        {
            cout << "Negative Cycle Here.";
            return;
        }
    }
    for (int i=0;i<N;i++)
    {
        cout<<"Distance of vertex "<<i<<" from the source "
             <<setw(2)<<distance[i]<<"    .Path is [ ";
        Path(parent,i);cout<<"]"<<'\n';
    }
}
int main()
{
    vector<Edge>edges=
    {
        { 0, 1, 2 },{ 1, 3, 4 },{ 0, 3, 6 }
    };
    int N=5;
    int source=0;
    Bell_f(edges,source,N);
    return 0;
}

