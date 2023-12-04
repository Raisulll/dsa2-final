#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000][1000];
vector<pair<ll,ll>> arr;
ll mark[1000][1000];
ll knapsack(ll ind, ll w)
{
    if(ind<0 or w<=0) return 0;
    if(dp[ind][w]!=-1) return dp[ind][w];
    ll x=0,y=0;
    x=knapsack(ind-1,w);
    if(w>=arr[ind].first)
    {
        y=knapsack(ind-1,w-arr[ind].first)+arr[ind].second;
    }
    if(x>y) mark[ind][w]=1;
    else mark[ind][w]=2;
    return dp[ind][w]= max(x,y);
}
void print(ll ind,ll w)
{
    if(ind<0) return;
    if(mark[ind][w]==2)
    {
        print(ind-1,w-arr[ind].first);
        cout<<arr[ind].first<<" "<<arr[ind].second<<endl;
    }
    else if(mark[ind][w]==1)
    {
        print(ind-1,w);
    }
}
int main()
{
    memset(dp,-1,sizeof dp);
    memset(mark,-1,sizeof mark);
    ll n,w; 
    cin>>n>>w;
    arr.resize(n);
    for(auto &it:arr) cin>>it.first>>it.second;
    // for(auto it:arr) cout<<it.first<<" "<<it.second<<endl;
    cout<<knapsack(n-1,w)<<endl;
    print(n-1,w);
}