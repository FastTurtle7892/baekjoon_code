#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    vector<int> top(4, INT_MIN);

    for (int x : arr) {

        int idx = -1;

        for (int k = 0; k < 4; k++) {
            if (top[k] < x && (idx == -1 || top[k] > top[idx])) {
                idx = k;
            }
        }
        if (idx == -1) {     
            cout << "NO\n";
            return 0;
        }
        top[idx] = x;        
    }

    cout << "YES\n";
    return 0;
}
