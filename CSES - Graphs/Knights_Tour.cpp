#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
int dy[8] = {-1, +1, -2, +2, -2, +2, -1, +1};

bool isValid(int x, int y, vector<vector<int>> &visited) {
    return x >= 0 && x < 8 && y >= 0 && y < 8 && visited[x][y] == 0;
}

int countOnwardMoves(int x, int y, vector<vector<int>> &visited) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isValid(nx, ny, visited)) count++;
    }
    return count;
}

bool knightTour(int x, int y, int moveCount, vector<vector<int>> &visited) {
    visited[x][y] = moveCount;
    if (moveCount == 64) return true;

    vector<tuple<int, int, int>> moves;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isValid(nx, ny, visited)) {
            int degree = countOnwardMoves(nx, ny, visited);
            moves.push_back({degree, nx, ny});
        }
    }

    sort(moves.begin(), moves.end());

    for (auto &[_, nx, ny] : moves) {
        if (knightTour(nx, ny, moveCount + 1, visited)) return true;
    }

    visited[x][y] = 0;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> visited(8, vector<int>(8, 0));

    if (knightTour(n, m, 1, visited)) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << visited[i][j] << " ";
            }
            cout << '\n';
        }
    } else {
        cout << "No complete tour found\n";
    }

    return 0;
}
