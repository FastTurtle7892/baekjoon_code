#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int board[1001][1001];
long long visited[1001][1001];
int check[1001][1001];
int dr[3][2] = { {0,1}, {1,0}, {1,1} };

int R, C;

void init() {

    cin >> R >> C;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> board[r][c];
        }
    }
}

int isOutBound(int r, int c) {
    return !(0 <= r && r < R && 0 <= c && c < C);
}

int process() {

    queue<pair<int, int>> q;
    visited[0][0] = board[0][0];
    q.push({ 0,0 });


    while(!q.empty()) {

        int now_r = q.front().first;
        int now_c = q.front().second;
        q.pop();

        for (int d = 0; d < 3; d++) {

            int f_r = now_r + dr[d][0];
            int f_c = now_c + dr[d][1];

            if (isOutBound(f_r, f_c)) continue;

            if (check[f_r][f_c] == 0) {
                check[f_r][f_c] = 1;
                q.push({ f_r, f_c });
                visited[f_r][f_c] = visited[now_r][now_c] + board[f_r][f_c];
            }
            else if (visited[f_r][f_c] < visited[now_r][now_c] + board[f_r][f_c]) {
                visited[f_r][f_c] = visited[now_r][now_c] + board[f_r][f_c];
                q.push({ f_r, f_c });
            }
        }
    }
    return visited[R - 1][C - 1];
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    long long res = process();

    cout << res << "\n";

    return 0;
}
