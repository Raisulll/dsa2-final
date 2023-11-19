#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define nl "\n"
#define printa(a, L, R)         \
    for (int i = L; i < R; i++) \
    cout << a[i] << (i == R - 1 ? '\n' : ' ')
#define pb push_back
#define UB upper_bound
#define LB lower_bound
#define F first
#define S second
#define mem(a, x) memset(a, x, sizeof(a))
ll cs;
#define _case cout << "Case " << ++cs << ": "
#define rev(v) reverse(v.begin(), v.end())
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
const ll infi = 1e18;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 3;
float pi = 3.141592653589793238462643383279502884197;
// ll dx[]={1,0,-1,0,1,-1,-1,1};
// ll dy[]={0,1,0,-1,1,1,-1,-1};
void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll m[100][100] = {0}, s[100][100] = {0};
    for (auto &it : arr)
        cin >> it;
    for (ll d = 1; d < n - 1; ++d)
    {
        for (ll i = 1; i < n - d; ++i)
        {
            ll j = i + d;
            ll mn = infi;
            for (ll k = i; k < j; ++k)
            {
                ll q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < mn)
                {
                    mn = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = mn;
        }
    }
    cout << m[1][n - 1] << nl;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    // cin.ignore();
    while (t--)
    {
        solve();
    }
    return 0;
}