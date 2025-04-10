#include <bits/stdc++.h>
using namespace std;

bool bfs(int i, vector<vector<int>> &arr, vector<int> &team) {
    team[i] = 1;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int nei: arr[node]) {
            if (team[nei] == 0) {
                team[nei] = 3 - team[node];
                q.push(nei);
            } else if (team[nei] == team[node]) return false;
        }
    }
    return true;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> arr(n+1);
    for (int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    vector<int> team(n+1, 0);
    for (int i=1; i<=n; i++) {
        if (team[i] == 0) {
            if (!bfs(i, arr, team)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << team[i] << " ";
    }
}