#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> vec;


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    int input;
    for (int i = 0; i < N; i++) {
        cin >> input; vec.push_back(input);
    }

    int cnt_down = 0;
    int memory_idx = 0;
    for (int i = 1; i < N; i++) {

        if (vec[i - 1] > vec[i]) {
            cnt_down++;
            memory_idx = i - 1;
        }
    }

    if (cnt_down == 0) {
        cout << N << "\n";
    }
    else if (cnt_down >= 2) {
        cout << 0 << "\n";
    }
    else{
        int ans = 0;
        // 제외한 인덱스 오른쪽이 마지막 인덱스라면

        // memory_idx + 1를 뺀경우
        if (memory_idx + 1 == N - 1 || vec[memory_idx] <= vec[memory_idx + 2])
            ans++;

        // memory_idx 를 뺀 경우
        if (memory_idx == 0 || vec[memory_idx - 1] <= vec[memory_idx + 1])
            ans++;
        cout << ans << "\n";

    }
    return 0;
}
