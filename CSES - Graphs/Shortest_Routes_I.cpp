#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [dis, node] = pq.top();
        pq.pop();
        if (dist[node] < dis) continue;
        for (auto it: graph[node]) {
            int edgeWeight = it.second;
            int adjNode = it.first;
            if (dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dis + edgeWeight, adjNode});
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << dist[i] << " ";
    cout << endl;
    return 0;
}
