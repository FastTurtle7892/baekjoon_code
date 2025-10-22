#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

vector<long long> vec;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M; cin >> N >> M;
    vec.assign(N, 0);

    long long max_len = 0;
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
        max_len = max(max_len, vec[i]);
    }

    long long left_val = 1;
    long long right_val = max_len;
    long long ans = 0;


    while (left_val <= right_val) {

        long long now_sum = 0;
        long long mid = (left_val + right_val) / 2;

        for (int i = 0; i < N; i++) {
            now_sum += vec[i] / mid;
        }

        if (now_sum >= M) {
            ans = mid;
            left_val = mid + 1;
        }
        else {
            right_val = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}

