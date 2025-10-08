#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <stdint.h>

using namespace std;

int dp[50'001];

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;

        for (int j = 1; j*j <= i; j++) {

            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }

    }
    cout << dp[N] << "\n";
    return 0;
}


