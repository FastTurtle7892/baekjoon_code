#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// arr[i] + arr[j] + arr[k] = arr[x]
// arr[x] - arr[k] = arr[i] + arr[j] 와 같다.

vector<int> arr;
vector<int> sum_arr;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;  cin >> N;

    int input;
    for (int i = 0; i < N; i++) {

        cin >> input;
        arr.push_back(input);
    }


    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum_arr.push_back(arr[i] + arr[j]);
        }
    }
    sort(arr.begin(), arr.end());
    sort(sum_arr.begin(), sum_arr.end());

    int max_val = 0;
    for (int i = N-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {

            if (binary_search(sum_arr.begin(), sum_arr.end(), arr[i] - arr[j])) {

                max_val = max(max_val, arr[i]);
            }
        }
    }
    cout << max_val << "\n";
    return 0;
}
