#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int dp[305][2];
int score[305];
int N;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 1; i <= N; i++) {

        cin >> score[i];
    }

    dp[1][1] = score[1];
    dp[1][2] = 0;
    dp[2][1] = score[2];
    dp[2][2] = score[1] + score[2];

    for (int i = 3; i <= N; i++) {

        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + score[i];
        dp[i][2] = dp[i - 1][1] + score[i];
    }

    cout << max(dp[N][1], dp[N][2]) << "\n";

    return 0;
}


