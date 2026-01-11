#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, stack<int> &st, int n) {
    visited[node] = true;
    for (auto it: graph[node]) {
        if (!visited[it]) {
            dfs(it, graph, visited, st, n);
        }
    }
    st.push(node);
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n+1);
    for (int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    stack<int> st;
    vector<bool> visited(n+1, false);
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, st, n);
        }
    }
    vector<int> distance(n+1, INT_MIN);
    vector<int> parent(n+1, -1);
    distance[1] = 0;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (distance[u] != INT_MIN) {
            for (int v : graph[u]) {
                if (distance[u] + 1 > distance[v]) {
                    distance[v] = distance[u] + 1;
                    parent[v] = u;
                }
            }
        }
    }
    if (distance[n] == INT_MIN) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> path;
    for (int cur = n; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (auto i: path) {
        cout << i << " ";
    }
}