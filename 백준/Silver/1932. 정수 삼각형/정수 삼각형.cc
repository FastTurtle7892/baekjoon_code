#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <stdint.h>

using namespace std;

int triangle[501][501];
int dp[501][501];

int N;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    dp[1][1] = triangle[1][1];

    for (int i = 2; i <= N; i++) {

        for (int j = 1; j <= i; j++) {

            dp[i][j] = max(dp[i][j], dp[i - 1][j] + triangle[i][j]);
            if (j > 1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
        }
    }

    int max_val = 0;
    for (int i = 1; i <= N; i++) {
        
        max_val = max(max_val, dp[N][i]);
    }
    cout << max_val << "\n";
    return 0;
}


