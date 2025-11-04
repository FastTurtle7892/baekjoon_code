#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

vector<int> weight;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, K; cin >> N >> K;

    weight.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> weight[i];
    }

    sort(weight.begin(), weight.end());

    int s_idx = 0;
    int e_idx = N - 1;

    int ans = 0;

    while (s_idx < e_idx) {

        int now_sum = weight[s_idx] + weight[e_idx];
        if (now_sum > K) {
            e_idx--;
        }
        else {
            ans++;
            s_idx++;
            e_idx--;
        }
    }
    cout << ans << "\n";


    return 0;
}

// 16 11 8 4 2
// 9 7 6 5 4 3
