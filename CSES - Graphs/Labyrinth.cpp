#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dir[] = {'D', 'U', 'R', 'L'};

bool isValid(const int i, const int j, const int n, const int m) {
    if (i < 0 || i >= n || j < 0 || j >= m) return false;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> rooms(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));
    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rooms[i][j];
            if (rooms[i][j] == 'A') start = {i, j};
            if (rooms[i][j] == 'B') end = {i, j};
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ni = node.first + dx[i];
            int nj = node.second + dy[i];
            if (isValid(ni, nj, n, m) && rooms[ni][nj] != '#' && !visited[ni][nj]) {
                visited[ni][nj] = true;
                parent[ni][nj] = node;
                q.emplace(ni, nj);
            }
        }
    }

    if (!visited[end.first][end.second]) {
        cout << "NO" << endl;
    } else {
        pair<int, int> curr = end;
        string res;

        while (curr != start) {
            auto [px, py] = parent[curr.first][curr.second];
            for (int i=0; i<4; i++) {
                if (px + dx[i] == curr.first && py + dy[i] == curr.second) {
                    res += dir[i];
                    break;
                }
            }
            curr = {px, py};
        }

        reverse(res.begin(), res.end());
        cout << "YES\n" << res.size() << "\n" << res << endl;
    }
}