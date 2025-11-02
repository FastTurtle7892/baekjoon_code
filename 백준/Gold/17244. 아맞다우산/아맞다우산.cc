#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

char board[51][51];
int board_visited[51][51];
int R, C;

pair<int, int> start_pos;
pair<int, int> end_pos;
vector<pair<int, int>> um_pos;
vector<int> visited;
int ans = INT_MAX;
int dr[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

void init() {

    cin >> C >> R;

    string str;

    for (int r = 0; r < R; r++) {
        cin >> str;

        for (int c = 0; c < C; c++) {

            board[r][c] = str[c];

            if (board[r][c] == 'S') {
                start_pos = { r,c };
                board[r][c] = '.';
            }
            if (board[r][c] == 'E') {
                end_pos = { r,c };
                board[r][c] = '.';
            }
            if (board[r][c] == 'X') {
                um_pos.push_back({ r,c });
                board[r][c] = '.';
            }
        }
    }
    visited.assign(um_pos.size(), 0);
}

void init_board_visited() {

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {

            board_visited[r][c] = 0;
        }
    }
}

int isOutBound(int r, int c) {
    return !(0 <= r && r < R && 0 <= c && c < C);
}

int bfs(pair<int, int> s, pair<int, int> e) {

    queue<pair<int, int>> q;
    init_board_visited();

    board_visited[s.first][s.second] = 1;
    q.push(s);

    while (!q.empty()) {

        int now_r = q.front().first;
        int now_c = q.front().second;

        q.pop();

        if (now_r == e.first && now_c == e.second) {

            return board_visited[now_r][now_c] - 1;
        }

        for (int d = 0; d < 4; d++) {

            int f_r = now_r + dr[d][0];
            int f_c = now_c + dr[d][1];

            if (isOutBound(f_r, f_c)) continue;
            if (board[f_r][f_c] == '#') continue;
            if (board_visited[f_r][f_c]) continue;


            q.push({ f_r, f_c });
            board_visited[f_r][f_c] = board_visited[now_r][now_c] + 1;
        }
    }
    return -1;
}

int process(vector<int>& tmp) {

    int total_time = 0;
    pair<int, int> start_pos_tmp = start_pos;
    for (int i = 0; i < tmp.size(); i++) {

        int tmp_res = bfs(start_pos_tmp, um_pos[tmp[i]]);
        if (tmp_res == -1) return INT_MAX;
        else {
            total_time += tmp_res;
            start_pos_tmp = um_pos[tmp[i]];
        }
    }
    int tmp_res2 = bfs(start_pos_tmp, end_pos);
    if (tmp_res2 == -1) return INT_MAX;
    else {
        total_time += tmp_res2;
    }
    return total_time;
}

void dfs(vector<int>& tmp) {

    if (tmp.size() == um_pos.size()) {

        int res = process(tmp);
        ans = min(res, ans);
        return;
    }
    for (int i = 0; i < um_pos.size(); i++) {

        if (visited[i]) continue;

        visited[i] = 1;
        tmp.push_back(i);
        dfs(tmp);
        tmp.pop_back();
        visited[i] = 0;
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    vector<int> tmp;
    dfs(tmp);

    cout << ans << "\n";
    return 0;
}


