#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        arr.insert(u);
    }
    cout << arr.size() << endl;
}