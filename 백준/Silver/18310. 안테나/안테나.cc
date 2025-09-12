#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> vec;

int ans_idx = 0;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    int input;
    int min_val = INT_MAX;
    int max_val = 0;
    for (int i = 0; i < N; i++) {
        cin >> input;
        vec.push_back(input);
        min_val = min(min_val, input);
        max_val = max(max_val, input);
    }
    sort(vec.begin(), vec.end());

    // vec 의 중간값

    // 짝수개 vec -> ex) N=4 => 중간값 인덱스 : 1 => (N-1)/2
    // 홀수개 vec -> ex) N=3 => 중간값 인덱스 : 1 => (N-1)/2

    cout << vec[(N-1)/2] << "\n";
    return 0;
}
