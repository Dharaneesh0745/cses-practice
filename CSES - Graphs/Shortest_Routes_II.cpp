#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
long long dist[501][501];

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }
    for (int i=0; i<m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[a][b] << endl;
        }
    }
}