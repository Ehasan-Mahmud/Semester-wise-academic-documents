#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
int partition(int a[],int p,int r)
{
    int i=p;
    for(int j=p;j<r;j++){
        if(a[j]<a[r]){
            swap(a[j],a[i]);
            i++;
        }
    }
    swap(a[i],a[r]);
    return i;
}
void quicksort(int a[],int p, int r)
{
    if(p>=r) return;
    int i=partition(a,p,r);
    quicksort(a,p,i-1);
    quicksort(a,i+1,r);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
