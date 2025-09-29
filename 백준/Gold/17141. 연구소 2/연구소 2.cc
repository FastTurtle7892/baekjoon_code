#include <iostream>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

// 1. dfs로 가능한 모든 조합 찾기
// 2. 찾은 조합으로 bfs 돌리기

int N, M;

int board[51][51];
int visited[51][51];


vector<pair<int, int>> virus_pos;

int ans = INT_MAX;

int dr[4][2] = { {0,1}, {1,0} ,{-1,0}, {0,-1} };
int virus_pos_cnt = 0;
void init() {

    cin >> N >> M;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> board[r][c];
            if (board[r][c] == 2) {
                virus_pos.push_back({ r,c });
                virus_pos_cnt++;
            }
        }
    }
}

int isOutBound(int r, int c) {
    return !(0 <= r && r < N && 0 <= c && c < N);
}

void init_visited() {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            visited[r][c] = 0;
        }
    }
}

bool check() {

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (board[r][c] == 1) continue;
            else if (visited[r][c] == 0) return false;
        }
    }
    return true;
}

void bfs(vector<pair<int, int>>& tmp_pos) {

    queue<pair<int, int>> q;
    init_visited();
    for (int i = 0; i < M; i++) {
        visited[tmp_pos[i].first][tmp_pos[i].second] = 1;
        q.push({ tmp_pos[i] });
    }

    int cnt = 0;
    while (!q.empty()) {

        int q_size = q.size();
        for (int q_cnt = 0; q_cnt < q_size; q_cnt++) {

            int now_r = q.front().first;
            int now_c = q.front().second;

            q.pop();

            for (int d = 0; d < 4; d++) {

                int f_r = now_r + dr[d][0];
                int f_c = now_c + dr[d][1];

                if (isOutBound(f_r, f_c)) continue;
                if (visited[f_r][f_c]) continue;
                if (board[f_r][f_c] == 1) continue;

                visited[f_r][f_c] = 1;
                q.push({ f_r, f_c });
             
            }
        }
        if(q.size() > 0)
            cnt++;
    }
    if (check()) {
        ans = min(ans, cnt);
    }
}

void dfs(int idx, vector<pair<int, int>> &tmp_pos) {

    if (tmp_pos.size() == M) {

        bfs(tmp_pos);
        return;
    }
    for (int i = idx; i < virus_pos_cnt; i++) {

        tmp_pos.push_back(virus_pos[i]);
        dfs(i + 1, tmp_pos);
        tmp_pos.pop_back();
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    vector<pair<int, int>> tmp_pos;
    dfs(0, tmp_pos);

    if (ans == INT_MAX) {
        cout << -1 << "\n";
    }
    else cout << ans << "\n";

    return 0;
}