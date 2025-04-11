#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    long long k;
    cin >> n >> m >> k;
    vector<vector<pair<long long, long long>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
    pq.push({0, 1});
    vector<vector<long long>> dist(n+1);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        size_t z = dist[u].size();
        if (z >= k) continue;
        dist[u].push_back(d);
        for (auto [v, w]: graph[u]) {
            pq.push({d + w, v});
        }
    }
    for (long long i: dist[n]) cout << i << " ";
}