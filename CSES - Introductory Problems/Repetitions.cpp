#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    char prev = s[0];
    long long curr_cnt = 1;
    long long max_cnt = 0;
    for (size_t i = 1; i < s.length(); i++) {
        if (s[i] == prev) {
            curr_cnt++;
        } else {
            max_cnt = max(max_cnt, curr_cnt);
            curr_cnt = 1;
        }
        prev = s[i];
    }
    max_cnt = max(max_cnt, curr_cnt);
    cout << max_cnt << endl;
}