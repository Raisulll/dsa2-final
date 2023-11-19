// graph coloring - all possible solutions
#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> graph;
vector<int> colors;

bool isSafe(int node, int color)
{
    for (auto it : graph[node])
    {
        if (colors[it] == color)
            return false;
    }
    return true;
}

bool graphColoring(int node, int n_color)
{
    if (node == colors.size())
    {
        for (int i = 0; i < colors.size(); i++)
            cout << colors[i] << " ";
        cout << endl;
        return false;
    }
    for (int i = 1; i <= n_color; ++i)
    {
        if (isSafe(node, i))
        {
            colors[node] = i;
            if (graphColoring(node + 1, n_color))
                return true;
            colors[node] = 0;
        }
    }
    return false;
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    int u, v;
    for (int i = 0; i < edge; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int n_color;
    cin >> n_color;
    colors.resize(node, 0);
    graphColoring(0, n_color);
    return 0;
}
//--------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> graph;
vector<int> colors;

bool isSafe(int node, int color)
{
    for (auto it : graph[node])
    {
        if (colors[it] == color)
            return false;
    }
    return true;
}

bool graphColoring(int node, int n_color, int &minColors)
{
    if (node == colors.size())
    {
        // Check the number of unique colors used
        set<int> uniqueColors(colors.begin(), colors.end());
        int currentColors = uniqueColors.size();

        // Update minimum colors if needed
        minColors = min(minColors, currentColors);

        return false; // Return false to explore all solutions
    }

    for (int i = 0; i < n_color; ++i)
    {
        if (isSafe(node, i))
        {
            colors[node] = i;
            graphColoring(node + 1, n_color, minColors);
            colors[node] = -1; // Reset color for backtracking
        }
    }
    return false;
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    int u, v;
    for (int i = 0; i < edge; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int minColors = INT_MAX;
    for (int n_color = 1; n_color <= node; ++n_color)
    {
        colors.resize(node, -1); // Initialize colors to -1
        graphColoring(0, n_color, minColors);
    }

    cout << "Minimum number of colors needed: " << minColors << endl;

    return 0;
}

