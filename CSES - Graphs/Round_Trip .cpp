#include <bits/stdc++.h>
using namespace std;

int start = -1, last = -1;

bool dfs(int node, int par, vector<int> &vis, vector<int> &parent, vector<vector<int>> &arr) {
    vis[node] = 1;
    for (auto i : arr[node]) {
        if (i == par) continue;
        if (vis[i]) {
            start = i;
            last = node;
            return true;
        } else {
            parent[i] = node;
            if (dfs(i, node, vis, parent, arr)) return true;
        }
    }
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> arr(n + 1);
    vector<int> parent(n + 1, -1), vis(n + 1, 0);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i, -1, vis, parent, arr)) break;
    }

    if (start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        for (int v = last; v != start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(start);
        cycle.push_back(last);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (int v : cycle)
            cout << v << " ";
        cout << "\n";
    }
}