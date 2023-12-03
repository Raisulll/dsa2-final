#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,c;
map<ll,vector<ll>>mp;
map<ll,ll>degree;
void Topsort(vector<ll>&ans)
{
    bool flag=false;
    for(ll i=0; i<n; ++i)
    {
        if(!degree[i])
        {
            flag=true;
            degree[i]=-1;
            ans.push_back(i);
            for(auto it:mp[i])
            {
                degree[it]--;
            }
            Topsort(ans);
            degree[i]=0;
            for(auto it:mp[i])
            {
                degree[it]++;
            }
            ans.pop_back();
        }
    }
    if(!flag)
    {
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        c++;
    }
}
int main()
{
    cin>>n;
    for(ll i=0; i<n; ++i)
    {
        ll x,y; cin>>x>>y;
        mp[x].push_back(y);
        degree[y]++;
    }
    vector<ll>ans;
    Topsort(ans);
    if(!c)
    {
        cout<<"No topological sort exists!!\n";
    }
}
/*
6
5 2
5 0
4 0
4 1
2 3
3 1
*/