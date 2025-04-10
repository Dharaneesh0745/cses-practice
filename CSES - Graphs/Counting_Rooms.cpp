#include<bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int r, int c) {
    if (i >= 0 && i < r && j >= 0 && j < c) return true;
    return false;
}

bool dfs(int i, int j, vector<vector<char>> &rooms, vector<vector<bool>> &visited, int r, int c) {
    if (!isValid(i, j, r, c)) return false;
    if (rooms[i][j] == '#' || visited[i][j]) return false;

    visited[i][j] = true;
    dfs(i+1, j, rooms, visited, r, c);
    dfs(i-1, j, rooms, visited, r, c);
    dfs(i, j+1, rooms, visited, r, c);
    dfs(i, j-1, rooms, visited, r, c);

    return true;
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> rooms(r, vector<char>(c, '#'));
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            char ch;
            cin >> ch;
            if (ch != '#')
                rooms[i][j] = ch;
        }
    }
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    int count = 0;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (rooms[i][j] == '.' && !visited[i][j]) {
                dfs(i, j, rooms, visited, r, c);
                count++;
            }
        }
    }
    cout << count << endl;
}