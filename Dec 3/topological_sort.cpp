#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> mp;
map<int, int> inD;
vector<int> ans;

void allTopSortUtil(vector<int>& res, bool visited[]) {
    bool flag = false;

    for (auto it : mp) {
        int i = it.first;
        if (inD[i] == 0 && !visited[i]) {
            for (auto j : mp[i])
                inD[j]--;

            res.push_back(i);
            visited[i] = true;
            allTopSortUtil(res, visited);

            visited[i] = false;
            res.erase(res.end() - 1);
            for (auto j : mp[i])
                inD[j]++;

            flag = true;
        }
    }

    if (!flag) {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}

void allTopSort() {
    bool *visited = new bool[mp.size()];
    for (int i = 0; i < mp.size(); i++)
        visited[i] = false;

    vector<int> res;
    allTopSortUtil(res, visited);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        inD[y]++;
    }
    allTopSort();
    return 0;
}
