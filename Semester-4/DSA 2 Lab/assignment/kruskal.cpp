#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int k,a,b,u,v,n,ne=1;
int mincost=0;
int cost[3][3]={
    {0, 10, 20},{12, 0, 15},{16, 18, 0}};
int p[9]={0};
int aFind(int i)
{
    while (p[i]!=0) {
        i=p[i];
    }
    return i;
}
int aUnion(int i,int j)
{
    if (i!=j) {
        p[j]=i;
        return 1;
    }
    return 0;
}
int main()
{
    n=3;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (cost[i][j]==0) {
                cost[i][j]=inf;
            }
        }
    }
    //cout <<"Minimum Spanning Tree:";
    cout<<endl;
    while (ne<n) {
        int min_val=inf;
        for (int i=0;i<n;i++) {
            for (int j=0;
                    j<n;j++) {
                if (cost[i][j]<min_val) {
                    min_val=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=aFind(u);
        v=aFind(v);
        if (aUnion(u, v)!=0) {
            //cout <<a<<"->"<<b<<"\n";
            mincost +=min_val;
        }
        cost[a][b]=cost[b][a]=999;
        ne++;
    }
    cout <<"Minimum cost="<<mincost<<endl;
    return 0;
}

