#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> res;

void dfs(long long i, vector<bool> &visited, vector<vector<long long>> &arr, vector<long long> &temp) {
    visited[i] = true;
    temp.push_back(i);
    for (long long j : arr[i]) {
        if (!visited[j]) {
            dfs(j, visited, arr, temp);
        }
    }
}

int main() {
    long long n, e;
    cin >> n >> e;
    vector<vector<long long>> arr(n + 1);
    for (long long i = 0; i < e; i++) {
        long long u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    for (long long i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<long long> temp;
            dfs(i, visited, arr, temp);
            res.push_back(temp);
        }
    }

    vector<long long> ans;
    long long cnt = 0;
    for (size_t i = 0; i < res.size()-1; i++) {
        ans.push_back(res[i][0]);
        ans.push_back(res[i+1][0]);
        cnt++;
    }
    cout << cnt << endl;
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
