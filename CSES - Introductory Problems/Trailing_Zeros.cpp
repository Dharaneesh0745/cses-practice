#include <bits/stdc++.h>
using namespace std;

unsigned long factorial(unsigned long n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    long long n;
    cin >> n;
    string s = to_string(factorial(n));
    long long max_cnt = 0;
    long long curr_cnt = 0;
    char prev = s[0];
    if (prev == '0') {
        curr_cnt++;
    }
    for (size_t i = 1; i < s.length(); i++) {
        if (prev == '0' && s[i] == '0') curr_cnt++;
        else {
            max_cnt = max(max_cnt, curr_cnt);
            curr_cnt = 0;
        }
    }
}