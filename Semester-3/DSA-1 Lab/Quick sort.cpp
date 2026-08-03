#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int partition(int a[],int p,int r)
{
    int i=p;
    for(int j=p; j<r; j++)
    {
        if(a[j]<a[r])
        {
            swap(a[j],a[i]);
            i++;
        }
    }
    swap(a[i],a[r]);
    return i;
}
void quicksort(int a[],int p,int r)
{
    if(p>=r) return;
    int i = partition(a,p,r);
    quicksort(a,p,i-1);
    quicksort(a,i+1,r);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    int s=n;
    for (int i=0; i<s; i++)
    {
        cin>>a[i];
    }
    quicksort(a,0,s-1);
    for(int i=0; i<s; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
/*
12
7 6 5 4 9 0 8 7 6 51 2 0
*/
