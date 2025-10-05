#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int N, M, K;

vector<vector<int>> arr;
int ans_cnt = 15;

void init() {

    cin >> N >> M;
    arr.assign(M, {});

    int input;
    for (int i = 0; i < M; i++) {
        cin >> K;
        for (int j = 0; j < K; j++) {
            cin >> input;
            arr[i].push_back(input);
        }
    }
}

void dfs(vector<int>& check_arr, int cnt, int idx) {

    if (ans_cnt < cnt) return;

    if (idx == M) {

        bool check_flag = true;
        for (int i = 1; i <= N; i++) {
            if (check_arr[i] == 0) {
                check_flag = false;
                break;
            }
        }

        if (check_flag) {
            ans_cnt = min(cnt, ans_cnt);
        }
        return;
    }

    dfs(check_arr, cnt, idx + 1);

    for (auto j : arr[idx]) check_arr[j] += 1;
    dfs(check_arr, cnt + 1, idx + 1);
    for (auto j : arr[idx]) check_arr[j] -= 1;
    
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    vector<int> check_arr(N + 1, 0);
    dfs(check_arr, 0, 0);

    if (ans_cnt == 15) cout << -1 << "\n";
    else cout << ans_cnt << "\n";

    return 0;
}

