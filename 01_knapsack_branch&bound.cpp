
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value, wt;
    Node(int value, int wt)
    {
        this->value = value;
        this->wt = wt;
    }
};

int parent[10005];

class Q
{
public:
    int ind, w, v, u;
    Q(int ind, int w, int v, int u)
    {
        this->ind = ind;
        this->w = w;
        this->v = v;
        this->u = u;
    }
};

int findUb(int v, int W, int w, int vnext, int wnext)
{
    return v + (W - w) * (vnext / wnext);
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<Node> v;
    for (int i = 0; i < n; i++)
    {
        int value, wt;
        cin >> wt >> value;
        Node temp(value, wt);
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), [&](const Node &a, const Node &b) -> bool
         { return (a.value / a.wt) > (b.value / b.wt); });
    queue<Q> qu;
    int mx = 0;
    int ub = findUb(0, w, 0, v[0].value, v[0].wt);
    qu.push({-1, 0, 0, ub});
    while (!qu.empty())
    {
        Q temp = qu.front();
        qu.pop();
        mx = max(mx, temp.v);
        int ind = temp.ind;
        if (ind + 2 > n)
            continue;
        int takeV = temp.v + v[ind + 1].value;
        int notakeV = temp.v;
        int takeW = temp.w + v[ind + 1].wt;
        int notakeW = temp.w;
        int takeUb = findUb(takeV, w, takeW, v[ind + 2].value, v[ind + 2].wt);
        int notakeUb =
            findUb(notakeV, w, notakeW, v[ind + 2].value, v[ind + 2].wt);
        if (takeW <= w && mx < takeUb)
            qu.push({ind + 1, takeW, takeV, takeUb});
        if (mx < notakeUb)
            qu.push({ind + 1, notakeW, notakeV, notakeUb});
    }
    cout << mx << endl;
}
