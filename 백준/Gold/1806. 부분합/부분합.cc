#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int arr[100002];
long long sum_arr[100002];

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    long long S;
    cin >> N >> S;

    int ans_len = INT_MAX;
    for (int i = 1; i <= N; i++) {

        cin >> arr[i];
        if (arr[i] == S) {
            cout << 1 << "\n";
            return 0;
        }
        sum_arr[i] = sum_arr[i - 1] + arr[i];
    }

    int start_idx = 0;
    int end_idx = 1;


    while (start_idx <= N && end_idx <= N) {

        if (sum_arr[end_idx] - sum_arr[start_idx] < S) {
            end_idx++;
        }
        else if (sum_arr[end_idx] - sum_arr[start_idx] == S) {

            ans_len = min(ans_len, end_idx - start_idx);
            end_idx++;
        }
        else {
            ans_len = min(ans_len, end_idx - start_idx);
            start_idx++;
        }
    }
    if (ans_len == INT_MAX) cout << 0 << "\n";
    else  cout << ans_len << "\n";
    return 0;
}

// 5 6 9 14 24 31 35 44 46 54

// 11 14 29 35 45