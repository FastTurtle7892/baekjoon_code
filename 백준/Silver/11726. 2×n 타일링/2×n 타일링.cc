#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <stdint.h>

using namespace std;

long long dp[1001];

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    if (N == 1 || N == 2) {
        cout << dp[N] << "\n";
        return 0;
    }

    for (int i = 3; i <= 1000; i++) {

        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= 10007;
    }

    cout << dp[N] << "\n";
    return 0;
}


