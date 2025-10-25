#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

vector<int> vec;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vec.assign(N, 0);

    int min_val = INT_MAX;
    int max_val = 0;
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
        min_val = min(min_val, vec[i]);
        max_val = max(max_val, vec[i]);
    }

    cout << 2 * (max_val - min_val) << "\n";

    return 0;
}

