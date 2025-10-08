#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long arr[1001];
long long dp[1001];

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


    int N; cin >> N;

    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] * 2;
        dp[i] %= 10'007;
    }
    
    cout << dp[N] << "\n";
    return 0;
}


