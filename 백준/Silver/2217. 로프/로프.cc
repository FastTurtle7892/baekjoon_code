#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<long long> vec;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end(), greater<>());
    long long ans = 0;

    for (int i = 0; i < vec.size(); i++) {
        ans = max(ans, (long long)vec[i] * (i + 1));
    }
    cout << ans << "\n";
    return 0;
}

// 문제 잘못읽음.
// 모든 로프를 다 쓰지 않아도 됨.
