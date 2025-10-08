#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long arr[100'001];
long long dp[100'001];

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    long long max_val = dp[1];
    for (int i = 2; i <= N; i++) {

        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        max_val = max(dp[i], max_val);
    }
    
    cout << max_val << "\n";
    return 0;
}


