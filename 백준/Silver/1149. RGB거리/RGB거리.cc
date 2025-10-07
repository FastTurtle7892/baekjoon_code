#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int dp[1001][4];
int N;

struct colors {

    int red;
    int green;
    int blue;
};

vector<colors> house;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    house.assign(N + 1, {});

    for (int i = 1; i <= N; i++) {

        cin >> house[i].red >> house[i].green >> house[i].blue;
    }
        
    // 빨강 : 1. 초록 : 2, 파랑 :3
    dp[1][1] = house[1].red;
    dp[1][2] = house[1].green;
    dp[1][3] = house[1].blue;


    for (int i = 2; i <= N; i++) {

        dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + house[i].red;
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + house[i].green;
        dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + house[i].blue;
    }

    cout << min({ dp[N][1], dp[N][2] , dp[N][3] });

    return 0;
}