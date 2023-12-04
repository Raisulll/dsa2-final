#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Node
{
public:
    ll v, w;
    Node(ll w, ll v)
    {
        this->v = v;
        this->w = w;
    }
};
class xyz
{
public:
    ll w, v, ind, ub;
    xyz(ll ind, ll w, ll v, ll ub)
    {
        this->ind = ind;
        this->w = w;
        this->v = v;
        this->ub = ub;
    }
};
ll calcu_ub(ll w, ll v, ll W, ll vnext, ll wnext)
{
    return v + (W - w) * (vnext / wnext);
}
int main()
{
    ll n, W;
    cin >> n >> W;
    vector<Node> V;
    for (ll i = 0; i < n; ++i)
    {
        ll x, y;
        cin >> x >> y;
        Node temp(x, y);
        V.push_back(temp);
    }
    sort(V.begin(), V.end(), [&](const Node &a, const Node &b) -> bool
         { return (a.v / a.w) > (b.v / b.w); });
    queue<xyz> q;
    ll x = calcu_ub(0, 0, W, V[0].v, V[0].w);
    q.push({-1, 0, 0, x});
    ll mx = 0;
    while (!q.empty())
    {
        xyz temp = q.front();
        q.pop();
        mx = max(mx, temp.v);
        ll i = temp.ind;
        if (i + 2 > n)
            continue;
        ll takeV = temp.v + V[i + 1].v;
        ll takeW = temp.w + V[i + 1].w;
        ll notakeV = temp.v;
        ll notakeW = temp.w;
        ll x = calcu_ub(takeW, takeV, W, V[i + 2].v, V[i + 2].w);
        ll y = calcu_ub(notakeW, notakeV, W, V[i + 2].v, V[i + 2].w);
        if (W >= takeW and mx < x)
            q.push({i + 1, takeW, takeV, x});
        if (mx < y)
            q.push({i + 1, notakeW, notakeV, y});
        cout<<mx<<endl;
    }
    cout << mx << endl;
}