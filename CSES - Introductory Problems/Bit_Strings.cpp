#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp, int mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;
    cout << power(2, n, MOD) << endl;
    return 0;
}