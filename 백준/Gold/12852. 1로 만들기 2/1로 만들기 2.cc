#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <stdint.h>

using namespace std;

int dp[1'000'001];
int p[1'000'001];
int N;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = N; i >= 1; i--) {

        if (dp[i - 1] == 0) {
            dp[i - 1] = dp[i] + 1;
            p[i - 1] = i;
        }
        else if (dp[i] + 1 < dp[i - 1]) {
            dp[i - 1] = dp[i] + 1;
            p[i - 1] = i;
        }
        if (i % 2 == 0) {
            if (dp[i / 2] == 0) {
                dp[i / 2] = dp[i] + 1;
                p[i / 2] = i;
            }
            else if (dp[i] + 1 < dp[i / 2]){
                dp[i / 2] = dp[i] + 1;
                p[i / 2] = i;
            }
        }
        if (i % 3 == 0) {
            if (dp[i / 3] == 0) {
                dp[i / 3] = dp[i] + 1;
                p[i / 3] = i;
            }
            else if (dp[i] + 1 < dp[i / 3]) {
                dp[i / 3] = dp[i] + 1;
                p[i / 3] = i;
            }
        }
    }
    cout << dp[1] << "\n";

    vector<int> ans;
    int now_num = 1;
    ans.push_back(now_num);
    
    while (now_num != N) {
        now_num = p[now_num];
        ans.push_back(now_num);
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}