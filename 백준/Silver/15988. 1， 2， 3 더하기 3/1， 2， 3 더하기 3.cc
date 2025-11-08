#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

long long dp[1'000'001];

long long process(int input) {

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= input; i++) {

        dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1'000'000'009;
        dp[i] %= 1'000'000'009;
    }
    return dp[input];
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    
    int input;
    for (int i = 0; i < N; i++) {

        cin >> input;
        cout << process(input) << "\n";
    }

    return 0;
}
