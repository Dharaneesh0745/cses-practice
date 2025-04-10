#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin>>n>>e;
    vector<vector<int>> arr(n+1);
    for (int i=0; i<e; i++) {
        int u, v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    vector<int> d(n+1, -1);
    vector<int> par(n+1, 0);
    queue<int> q;
    q.push(1);
    d[1] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i: arr[node]) {
            if (d[i] == -1) {
                d[i] = d[node] + 1;
                par[i] = node;
                q.push(i);
            }
        }
    }

    if (d[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> path;
    for (int i=n; i>0; i=par[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    cout << d[n] << endl;
    for (int i: path) {
        cout<<i<<" ";
    }
}