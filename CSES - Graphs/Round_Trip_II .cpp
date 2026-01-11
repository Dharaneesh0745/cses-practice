#include <bits/stdc++.h>
using namespace std;

long long start = -1, last = -1;

bool dfs(long long node, vector<long long> &vis, vector<long long> &parent, vector<vector<long long>> &adj) {
    vis[node] = 1;
    for (auto nei : adj[node]) {
        if (vis[nei] == 0) {
            parent[nei] = node;
            if (dfs(nei, vis, parent, adj)) return true;
        } else if (vis[nei] == 1) {
            start = nei;
            last = node;
            return true;
        }
    }
    vis[node] = 2;
    return false;
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> adj(n + 1);
    vector<long long> vis(n + 1, 0), parent(n + 1, -1);

    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (long long i = 1; i <= n; i++) {
        if (vis[i] == 0 && dfs(i, vis, parent, adj)) break;
    }

    if (start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<long long> cycle;
        cycle.push_back(start);
        for (long long v = last; v != start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(start);
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << "\n";
        for (auto v : cycle)
            cout << v << " ";
        cout << "\n";
    }
    return 0;
}