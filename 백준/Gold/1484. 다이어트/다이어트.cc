#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

vector<unsigned int> arr;
unsigned int N;


void init() {

    cin >> N;

    for (int i = 1; i <= 65535; i++) {
        arr.push_back(i * i);
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    vector<int> ans;
    int start_idx = 0;
    int end_idx = 1;

    while (start_idx < 65535 && end_idx < 65535) {

        if (arr[end_idx] - arr[start_idx] < N) {
            end_idx++;
        }
        else if (arr[end_idx] - arr[start_idx] > N) {
            start_idx++;
        }
        else {
            ans.push_back(sqrt(arr[end_idx]));
            end_idx++;
        }
    }
    if (ans.empty()) cout << -1 << "\n";
    else {
        for (auto i : ans)
            cout << i << "\n";
    }

    return 0;
}


