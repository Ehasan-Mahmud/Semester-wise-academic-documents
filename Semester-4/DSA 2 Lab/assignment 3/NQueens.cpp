#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
const ll MOD=998244353;
const ll MAX_SIZE=200005;
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
bool canPlaceQueen(ll n,vector<vector<ll>>& grid,ll col)
{
 if(col>=n)return true;
 for(ll row=0; row<n; row++)
 {
 bool isValid=true;
 for(ll i=0; i<col; i++)if(grid[row][i])isValid=false;
 for(ll i=col,j=row; i>=0&&j>=0; i--,j--)if(grid[j][i])isValid=false;
 for(ll i=col,j=row; i>=0&&j<n; i--,j++)if(grid[j][i])isValid=false;
 if(isValid)
 {
 grid[row][col]=1;
 if(canPlaceQueen(n,grid,col+1))return true;
 grid[row][col]=0;
 }
 }
 return false;
}

void solveNQueens()
{
 ll n=6;
 vector<vector<ll>>grid(n,vector<ll>(n,0));
 if(!canPlaceQueen(n,grid,0))
 {
 cout<<"No valid configuration found\n";
 return;
 }
 for(ll i=0; i<n; i++)
 {
 for(ll j=0; j<n; j++)cout<<grid[i][j]<<" ";
 cout<<endl;
 }
}
int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 solveNQueens();
 return 0;
}
