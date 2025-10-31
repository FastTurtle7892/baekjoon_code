#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int board[11][11];
int max_val = INT_MIN;
int N, M;

void combi(vector<int> &tmp, int idx) {

    if (tmp.size() == M) {

        int sum = 0;
        for (int i = 0; i < M; i++) {
            for (int j = i+1; j < M; j++) {
                sum += board[tmp[i]][tmp[j]];
            }
        }
        max_val = max(max_val, sum);
        return;
    }
    for (int i = idx; i < N; i++) {

        tmp.push_back(i);
        combi(tmp, i + 1);
        tmp.pop_back();
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> board[r][c];
        }
    }
    vector<int> tmp1;
    combi(tmp1, 0);

    cout << max_val << "\n";

    return 0;
}


