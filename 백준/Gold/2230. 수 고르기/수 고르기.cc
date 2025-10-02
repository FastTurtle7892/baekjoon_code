#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> arr;
    int input;
    for (int i = 0; i < N; i++) {

        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());



    if (N == 1) cout << arr[0] << "\n";


    else {
        int ans = INT_MAX;
        int start_idx = 0;
        int end_idx = 1;
        while (start_idx < N && end_idx < N) {

            if (arr[end_idx] - arr[start_idx] < M) {
                end_idx++;
            }
            else if (arr[end_idx] - arr[start_idx] == M) {
                
                ans = min(ans, M);
                end_idx++;
            }
            else {
                ans = min(ans, arr[end_idx] - arr[start_idx]);
                start_idx++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
