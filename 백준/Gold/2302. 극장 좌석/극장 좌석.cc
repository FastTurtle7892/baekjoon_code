#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long dp[41];

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M; cin >> N >> M;

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    long long res = 1;
    int s_val = 1;
    int input;

    for (int i = 0; i < M; i++) {
        cin >> input;
        res *= dp[input - s_val];
        s_val = input + 1;
    }
    res *= dp[N + 1 - s_val];

    cout << res << "\n";

    return 0;
}
