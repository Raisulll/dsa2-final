#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100][100],mark[100][100];
ll MCM(vector<ll> &arr, ll i, ll j)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = 1e12;
    for (ll k = i; k < j; ++k)
    {
        int mn=dp[i][j];
        dp[i][j] = min(dp[i][j], MCM(arr, i, k) + MCM(arr, k + 1, j) + arr[i - 1] * arr[j] * arr[k]);
        if(mn!=dp[i][j])
        {
            mark[i][j]=k;
        }
    }
    return dp[i][j];
}
void print_order(ll i, ll j)
{
    if(i==j) cout<<"X"<<i;
    else
    {
        cout<<"(";
        print_order(i,mark[i][j]);
        print_order(mark[i][j]+1,j);
        cout<<")";
    }
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &it : arr)
        cin >> it;
    memset(dp, -1, sizeof(dp));
    cout << MCM(arr, 1, n - 1)<<endl;
    print_order(1,n-1);
}