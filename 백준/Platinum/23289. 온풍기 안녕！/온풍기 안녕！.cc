#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

int R, C, K, M;
int board[21][21];
int add_board[21][21];

bool wall_up[21][21];    // (r,c) <-> (r-1,c)
bool wall_right_[21][21];// (r,c) <-> (r,c+1)

vector<pair<int, int>> check_pos;
vector<pair<int, int>> heaters[5]; // 1:→ 2:← 3:↑ 4:↓

inline bool OOB(int r, int c) { return r < 0 || r >= R || c < 0 || c >= C; }

// (r,c) -> (nr,nc) 이동이 벽으로 막히는지
bool blocked(int r, int c, int nr, int nc) {
    if (r == nr) {
        if (nc == c + 1) return wall_right_[r][c];
        if (nc == c - 1) return wall_right_[r][c - 1];
    }
    else if (c == nc) {
        if (nr == r - 1) return wall_up[r][c];
        if (nr == r + 1) return wall_up[r + 1][c];
    }
    return false;
}

void init() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> R >> C >> K;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            int v; cin >> v;
            if (v == 5) { check_pos.push_back({ r,c }); board[r][c] = 0; }
            else if (1 <= v && v <= 4) { heaters[v].push_back({ r,c }); board[r][c] = 0; }
            else board[r][c] = v; // 보드에 온도 초기값이 0 외에도 올 수 있는 입력은 없음(문제 정의상 0)이라도 안전하게
        }
    }
    cin >> M;
    memset(wall_up, 0, sizeof(wall_up));
    memset(wall_right_, 0, sizeof(wall_right_));
    for (int i = 0; i < M; i++) {
        int x, y, t; // 1-indexed
        cin >> x >> y >> t; x--; y--;
        if (t == 0) {
            // (x,y)와 (x-1,y) 사이
            // 우리 표기: wall_up[x][y] = true  (r,c)-(r-1,c)
            wall_up[x][y] = true;
        }
        else {
            // (x,y)와 (x,y+1) 사이
            wall_right_[x][y] = true;
        }
    }
}

// 바람 전파에서 (r,c) 기준, dir에 따른 3갈래 이동 후보와 그에 필요한 벽 체크
// true 이면 이동 가능
bool can_move_diag_up_right(int r, int c) { // (r,c)->(r-1,c)->(r-1,c+1)
    int a_r = r - 1, a_c = c, b_r = r - 1, b_c = c + 1;
    if (OOB(a_r, a_c) || OOB(b_r, b_c)) return false;
    if (blocked(r, c, a_r, a_c)) return false;       // 위로
    if (blocked(a_r, a_c, b_r, b_c)) return false;   // 오른쪽
    return true;
}
bool can_move_right(int r, int c) { // (r,c)->(r,c+1)
    int nr = r, nc = c + 1;
    if (OOB(nr, nc)) return false;
    if (blocked(r, c, nr, nc)) return false;
    return true;
}
bool can_move_diag_down_right(int r, int c) { // (r,c)->(r+1,c)->(r+1,c+1)
    int a_r = r + 1, a_c = c, b_r = r + 1, b_c = c + 1;
    if (OOB(a_r, a_c) || OOB(b_r, b_c)) return false;
    if (blocked(r, c, a_r, a_c)) return false;       // 아래로
    if (blocked(a_r, a_c, b_r, b_c)) return false;   // 오른쪽
    return true;
}

bool can_move_diag_up_left(int r, int c) {   // (r,c)->(r-1,c)->(r-1,c-1)
    int a_r = r - 1, a_c = c, b_r = r - 1, b_c = c - 1;
    if (OOB(a_r, a_c) || OOB(b_r, b_c)) return false;
    if (blocked(r, c, a_r, a_c)) return false;
    if (blocked(a_r, a_c, b_r, b_c)) return false;
    return true;
}
bool can_move_left(int r, int c) { // (r,c)->(r,c-1)
    int nr = r, nc = c - 1;
    if (OOB(nr, nc)) return false;
    if (blocked(r, c, nr, nc)) return false;
    return true;
}
bool can_move_diag_down_left(int r, int c) { // (r,c)->(r+1,c)->(r+1,c-1)
    int a_r = r + 1, a_c = c, b_r = r + 1, b_c = c - 1;
    if (OOB(a_r, a_c) || OOB(b_r, b_c)) return false;
    if (blocked(r, c, a_r, a_c)) return false;
    if (blocked(a_r, a_c, b_r, b_c)) return false;
    return true;
}

bool can_move_diag_left_up(int r, int c) { // (r,c)->(r,c-1)->(r-1,c-1)
    int a_r = r, a_c = c - 1, b_r = r - 1, b_c = c - 1;
    if (OOB(a_r, a_c) || OOB(b_r, b_c)) return false;
    if (blocked(r, c, a_r, a_c)) return false;
    if (blocked(a_r, a_c, b_r, b_c)) return false;
    return true;
}
bool can_move_up(int r, int c) { // (r,c)->(r-1,c)
    int nr = r - 1, nc = c;
    if (OOB(nr, nc)) return false;
    if (blocked(r, c, nr, nc)) return false;
    return true;
}
bool can_move_diag_right_up(int r, int c) { // (r,c)->(r,c+1)->(r-1,c+1)
    int a_r = r, a_c = c + 1, b_r = r - 1, b_c = c + 1;
    if (OOB(a_r, a_c) || OOB(b_r, b_c)) return false;
    if (blocked(r, c, a_r, a_c)) return false;
    if (blocked(a_r, a_c, b_r, b_c)) return false;
    return true;
}

bool can_move_diag_left_down(int r, int c) { // (r,c)->(r,c-1)->(r+1,c-1)
    int a_r = r, a_c = c - 1, b_r = r + 1, b_c = c - 1;
    if (OOB(a_r, a_c) || OOB(b_r, b_c)) return false;
    if (blocked(r, c, a_r, a_c)) return false;
    if (blocked(a_r, a_c, b_r, b_c)) return false;
    return true;
}
bool can_move_down(int r, int c) { // (r,c)->(r+1,c)
    int nr = r + 1, nc = c;
    if (OOB(nr, nc)) return false;
    if (blocked(r, c, nr, nc)) return false;
    return true;
}
bool can_move_diag_right_down(int r, int c) { // (r,c)->(r,c+1)->(r+1,c+1)
    int a_r = r, a_c = c + 1, b_r = r + 1, b_c = c + 1;
    if (OOB(a_r, a_c) || OOB(b_r, b_c)) return false;
    if (blocked(r, c, a_r, a_c)) return false;
    if (blocked(a_r, a_c, b_r, b_c)) return false;
    return true;
}

void blow_from(int sr, int sc, int dir) {
    // 시작 칸은 히터 앞 한 칸
    static int dr[5] = { 0,0,0,-1,1 }; // dummy, →,←,↑,↓
    static int dc[5] = { 0,1,-1,0,0 };

    int r = sr + dr[dir], c = sc + dc[dir];
    if (OOB(r, c)) return;
    if (blocked(sr, sc, r, c)) return;

    bool vis[21][21] = { 0 };
    queue<tuple<int, int, int>> q;
    q.emplace(r, c, 5);
    vis[r][c] = true;

    while (!q.empty()) {
        int cr = get<0>(q.front());
        int cc = get<1>(q.front());
        int temp = get<2>(q.front());
        q.pop();

        add_board[cr][cc] += temp;
        if (temp == 1) continue;

        if (dir == 1) { // →
            // 위-오른 대각
            if (can_move_diag_up_right(cr, cc)) {
                int nr = cr - 1, nc = cc + 1;
                if (!vis[nr][nc]) { vis[nr][nc] = true; q.emplace(nr, nc, temp - 1); }
            }
            // 직진
            if (can_move_right(cr, cc)) {
                int nr = cr, nc = cc + 1;
                if (!vis[nr][nc]) { vis[nr][nc] = true; q.emplace(nr, nc, temp - 1); }
            }
            // 아래-오른 대각
            if (can_move_diag_down_right(cr, cc)) {
                int nr = cr + 1, nc = cc + 1;
                if (!vis[nr][nc]) { vis[nr][nc] = true; q.emplace(nr, nc, temp - 1); }
            }
        }
        else if (dir == 2) { // ←
            if (can_move_diag_up_left(cr, cc)) {
                int nr = cr - 1, nc = cc - 1;
                if (!vis[nr][nc]) { vis[nr][nc] = true; q.emplace(nr, nc, temp - 1); }
            }
            if (can_move_left(cr, cc)) {
                int nr = cr, nc = cc - 1;
                if (!vis[nr][nc]) { vis[nr][nc] = true; q.emplace(nr, nc, temp - 1); }
            }
            if (can_move_diag_down_left(cr, cc)) {
                int nr = cr + 1, nc = cc - 1;
                if (!vis[nr][nc]) { vis[nr][nc] = true; q.emplace(nr, nc, temp - 1); }
            }
        }
        else if (dir == 3) { // ↑
            if (can_move_diag_left_up(cr, cc)) {
                int nr = cr - 1, nc = cc - 1;
                if (!vis[nr][nc]) { vis[nr][nc] = true; q.emplace(nr, nc, temp - 1); }
            }
            if (can_move_up(cr, cc)) {
                int nr = cr - 1, nc = cc;
                if (!vis[nr][nc]) { vis[nr][nc] = true; q.emplace(nr, nc, temp - 1); }
            }
            if (can_move_diag_right_up(cr, cc)) {
                int nr = cr - 1, nc = cc + 1;
                if (!vis[nr][nc]) { vis[nr][nc] = true; q.emplace(nr, nc, temp - 1); }
            }
        }
        else { // ↓
            if (can_move_diag_left_down(cr, cc)) {
                int nr = cr + 1, nc = cc - 1;
                if (!vis[nr][nc]) { vis[nr][nc] = true; q.emplace(nr, nc, temp - 1); }
            }
            if (can_move_down(cr, cc)) {
                int nr = cr + 1, nc = cc;
                if (!vis[nr][nc]) { vis[nr][nc] = true; q.emplace(nr, nc, temp - 1); }
            }
            if (can_move_diag_right_down(cr, cc)) {
                int nr = cr + 1, nc = cc + 1;
                if (!vis[nr][nc]) { vis[nr][nc] = true; q.emplace(nr, nc, temp - 1); }
            }
        }
    }
}

void heaters_blow() {
    memset(add_board, 0, sizeof(add_board));
    for (auto& p : heaters[1]) blow_from(p.first, p.second, 1);
    for (auto& p : heaters[2]) blow_from(p.first, p.second, 2);
    for (auto& p : heaters[3]) blow_from(p.first, p.second, 3);
    for (auto& p : heaters[4]) blow_from(p.first, p.second, 4);
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) board[r][c] += add_board[r][c];
}

void adjust_temperature() {
    static int diff[21][21];
    memset(diff, 0, sizeof(diff));
    int dr4[4] = { 0,0,-1,1 };
    int dc4[4] = { 1,-1,0,0 };

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            for (int k = 0; k < 4; k++) {
                int nr = r + dr4[k], nc = c + dc4[k];
                if (OOB(nr, nc)) continue;
                if (blocked(r, c, nr, nc)) continue;
                int d = (board[r][c] - board[nr][nc]) / 4;
                if (d > 0) { diff[r][c] -= d; diff[nr][nc] += d; }
            }
        }
    }
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            board[r][c] += diff[r][c];
}

void edge_cool() {
    // 윗줄
    for (int c = 0; c < C; c++) if (board[0][c] > 0) board[0][c]--;
    // 아랫줄
    for (int c = 0; c < C; c++) if (board[R - 1][c] > 0) board[R - 1][c]--;
    // 좌/우열 (모서리 중복 방지)
    for (int r = 1; r < R - 1; r++) {
        if (board[r][0] > 0) board[r][0]--;
        if (board[r][C - 1] > 0) board[r][C - 1]--;
    }
}

bool done() {
    for (auto& p : check_pos) {
        if (board[p.first][p.second] < K) return false;
    }
    return true;
}

int main() {
    init();

    int chocolate = 0;
    while (chocolate <= 100) {
        heaters_blow();       // 1
        adjust_temperature(); // 2
        edge_cool();          // 3
        chocolate++;          // 4
        if (done()) break;     // 5
    }
    cout << chocolate << "\n";
    return 0;
}
