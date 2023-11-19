#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<ll, vector<ll>> graph;
vector<ll> colors;

bool isSafe(ll node, ll c)
{
    for (auto it : graph[node])
    {
        if (colors[it] == c)
            return false;
    }
    return true;
}

bool graphColoring(ll node, ll c)
{
    if (node == colors.size())
    {
        for (ll i = 0; i < colors.size(); ++i)
            cout << colors[i] << " ";
        cout << endl;
        return true; // Return true to continue exploring all solutions
    }
    for (ll i = 1; i <= c; ++i)
    {
        if (isSafe(node, i))
        {
            colors[node] = i;
            if (graphColoring(node + 1, c))
                continue;;  // Return true to continue exploring all solutions
            colors[node] = 0; // Backtrack
        }
    }
    return false;
}

int main()
{
    ll n, e;
    cin >> n >> e;
    ll u, v;
    for (ll i = 0; i < e; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll c;
    cin >> c;
    colors.resize(n, 0);
    graphColoring(0, c);
    return 0;
}
