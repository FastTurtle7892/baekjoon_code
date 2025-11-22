#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int board[101][101];
int visited[101][101];
int N;

int min_h = 101;
int max_h = 0;

int dr[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

void init() {

    cin >> N;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> board[r][c];
            min_h = min(min_h, board[r][c]);
            max_h = max(max_h, board[r][c]);
        }
    }
}

int isOutBound(int r, int c) {
    return !(0 <= r && r < N && 0 <= c && c < N);
}

void bfs(int sr, int sc, int h) {

    queue<pair<int, int>> q;
    visited[sr][sc] = 1;
    q.push({ sr, sc });

    while(!q.empty()){
    
        int now_r = q.front().first;
        int now_c = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {

            int f_r = now_r + dr[d][0];
            int f_c = now_c + dr[d][1];

            if (isOutBound(f_r, f_c)) continue;
            if (visited[f_r][f_c]) continue;
            if (board[f_r][f_c] <= h) continue;

            q.push({ f_r, f_c });
            visited[f_r][f_c] = 1;
        }
    }
}

int find_component(int h) {

    int cnt = 0;
    memset(visited, 0, sizeof(visited));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {

            if (visited[r][c] == 0 && board[r][c] > h) {
                bfs(r, c, h);
                cnt++;
            }
        }
    }
    return cnt;
}

int process() {

    int ans = 1;
    for (int h = min_h; h <= max_h; h++) {

        ans = max(ans, find_component(h));
    }
    return ans;
}

int main() {

    ios::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
    
    init();

    int res = process();

    cout << res << "\n";

    return 0;
}