#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    int arr[n-1];
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n-1);
    long long summ = n*(n+1)/2;
    long long t = 0;
    for (int i = 0; i < n - 1; i++) {
        t += arr[i];
    }
    cout << summ - t << endl;
    return 0;
}