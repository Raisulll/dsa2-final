#include <bits/stdc++.h>
using namespace std;

int edges;
map<string, vector<string>> adj;
map<string, int> degree;
set<string> nodes;
vector<string> ans;
int c = 0;

void topo_sort(vector<string> &current)
{
    bool flag = false;
    // Traverse all the nodes and check if the degree is 0
    for (string i : nodes)
    {
        if (degree[i] == 0)
        {
            flag = true;
            degree[i] = -1; // Mark the node as visited
            current.push_back(i);

            // Reduce the degree of connected nodes
            for (string j : adj[i])
            {
                degree[j]--;
            }

            topo_sort(current);

            // Backtrack
            degree[i] = 0;
            current.pop_back();
            for (string j : adj[i])
            {
                degree[j]++;
            }
        }
    }

    if (!flag)
    {
        // All nodes are visited, print the topological sort
        for (auto i : current)
        {
            cout << i << " ";
        }
        cout << endl;
        c++;
    }
}

int main()
{
    int n;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        string u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        degree[v]++;
        nodes.insert(u);
        nodes.insert(v);
    }

    vector<string> current;
    topo_sort(current);

    if (c == 0)
    {
        cout << "No valid topological sorts." << endl;
    }

    return 0;
}