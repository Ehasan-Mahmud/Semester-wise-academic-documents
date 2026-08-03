#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

void merge(int a[], int p, int q){
    int mid = (p+q)/2;
    int n1 = mid - p + 1;
    int n2 = q - mid;
    int L[n1 + 1];
    int R[n2 + 1];

    for(int i=0; i<n1; i++) L[i] = a[p+i];
    for(int i=0; i<n2; i++) R[i] = a[mid+1+i];

    L[n1] = INF;
    R[n2] = INF;

    for(int k=p, i=0, j=0; k<=q; k++){
        if(L[i] < R[j]) a[k] = L[i++];
        else    a[k] = R[j++];
    }
}

void mergeSort(int a[], int p, int q){
    if(p>=q)    return;
    int mid = (p+q)/2;
    mergeSort(a, p, mid);
    mergeSort(a, mid+1, q);
    merge(a, p, q);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)  cin>>a[i];
    mergeSort(a, 0, n-1);
    for(int i=0; i<n; i++)  cout<<a[i]<<" ";
    return 0;
}
