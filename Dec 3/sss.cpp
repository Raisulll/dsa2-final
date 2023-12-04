#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void sss(vector<ll>&arr, vector<ll>&ans, ll i, ll n, ll ts)
{
    if(ts==0)
    {
        for(ll i=0; i<ans.size(); ++i)
            cout<<ans[i]<<" ";
        cout<<endl;
        return;
    }
    if(i==n) return;
    sss(arr,ans,i+1,n,ts);
    if(arr[i]<=ts)
    {
        ans.push_back(arr[i]);
        sss(arr,ans,i+1,n,ts-arr[i]);
        ans.pop_back();
    }
}
int main()
{
    ll n,s; cin>>n>>s;
    vector<ll>arr(n);
    for(auto &it:arr) cin>>it;
    vector<ll>ans;
    sss(arr,ans,0,n,s);

}