#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>


#ifdef _MSC_VER
#define __builtin_popcount __popcnt 
#endif

using namespace std;

int score[100'001];
int dp[100'001];
int N;



int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> score[i];
    }

    // XOR 결과의 1의 개수

    dp[2] = __builtin_popcount(score[1] ^ score[2]);
    dp[3] = __builtin_popcount(score[1] ^ score[2] ^ score[3]);
    dp[4] = __builtin_popcount(score[3] ^ score[4]) + dp[2];


    for (int i = 5; i <= N; i++) {

        dp[i] = max(__builtin_popcount(score[i - 1] ^ score[i]) + dp[i - 2], 
            __builtin_popcount(score[i-2] ^ score[i-1] ^ score[i]) + dp[i-3]);
    }

    cout << dp[N] << "\n";

    return 0;
}


