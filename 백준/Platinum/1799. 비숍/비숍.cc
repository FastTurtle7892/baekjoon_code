#include <iostream>
#include <cstring>
#include <queue>
#include <climits>
#include <vector>
#include <set>

using namespace std;

int N;

int board[11][11];
int check_ld[22];
int check_rd[22];

int cnt_odd = 0;
int cnt_even = 0;


void init() {

    cin >> N;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> board[r][c];
        }
    }
}

void dfs(int r, int c, int cnt, int tp) {

    if (c >= N) {
        r += 1;
        if (r % 2 == 0) c = tp;
        else c = 1 - tp;
    }

    if (r >= N) {
        if (tp == 0) {
            cnt_even = max(cnt_even, cnt);
        }
        else {
            cnt_odd = max(cnt_odd, cnt);
        }
        return;
    }

    if (board[r][c] == 1) {
        if (check_ld[r + c] == 0 && check_rd[c - r + N] == 0) {
            check_ld[r + c] = check_rd[c - r + N] = 1;
            dfs(r, c + 2, cnt + 1, tp);
            check_ld[r + c] = check_rd[c - r + N] = 0;
        }
    }
    dfs(r, c + 2, cnt, tp);
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    dfs(0, 0, 0, 0);
    dfs(0, 1, 0, 1);

    cout << cnt_odd + cnt_even << "\n";

    return 0;
}
