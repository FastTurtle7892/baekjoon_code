#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

vector<vector<int>> gama_int;
vector<vector<char>> gama_char;

vector<vector<vector<int>>> zeryo_int;
vector<vector<vector<char>>> zeryo_char;

int N;
vector<int> visited;
int ans = 0;

vector<pair<int, int>> start_pos = { {0,0}, {0,1}, {1,0}, {1,1} };

void init() {

    cin >> N;
    gama_int.assign(5, vector<int>(5, 0));
    gama_char.assign(5, vector<char>(5, 'W'));

    zeryo_int.assign(N, vector<vector<int>>(4, vector<int>(4, 0)));
    zeryo_char.assign(N, vector<vector<char>>(4, vector<char>(4, 'W')));

    visited.assign(N, 0);

    for (int i = 0; i < N; i++) {

        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                cin >> zeryo_int[i][r][c];
            }
        }
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                cin >> zeryo_char[i][r][c];
            }
        }
    }
}


void rotate_zeryo(int rot_time, vector<vector<int>>& tmp_int, vector<vector<char>>& tmp_char) {

    vector<vector<int>> tmp_int2(4, vector<int>(4, 0));
    vector<vector<char>> tmp_char2(4, vector<char>(4));

    for (int rot = 0; rot < rot_time; rot++) {

        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {

                tmp_int2[r][c] = tmp_int[c][3 - r];
                tmp_char2[r][c] = tmp_char[c][3 - r];
            }
        }
        tmp_int = tmp_int2;
        tmp_char = tmp_char2;
    }
}

int process() {

    vector<int> total_score(4, 0);

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (gama_char[r][c] == 'R') total_score[0] += gama_int[r][c];
            else if (gama_char[r][c] == 'B') total_score[1] += gama_int[r][c];
            else if (gama_char[r][c] == 'G') total_score[2] += gama_int[r][c];
            else if (gama_char[r][c] == 'Y') total_score[3] += gama_int[r][c];
        }
    }
    return 7 * total_score[0] + 5 * total_score[1] + 3 * total_score[2] + 2 * total_score[3];
}

void dfs(vector<int>& tmp) {

    if (tmp.size() == 3) {

        int res = process();
        ans = max(ans, res);
        return;
    }
    for (int i = 0; i < N; i++) {

        if (visited[i]) continue;

        visited[i] = 1;
        tmp.push_back(i);

        for (int rot = 0; rot < 4; rot++) {

            vector<vector<int>> tmp_int = zeryo_int[i];
            vector<vector<char>> tmp_char = zeryo_char[i];
            rotate_zeryo(rot, tmp_int, tmp_char);

            for (int pos = 0; pos < 4; pos++) {

                int r_offset = start_pos[pos].first;
                int c_offset = start_pos[pos].second;

                vector<vector<int>> gama_tmp_int = gama_int;
                vector<vector<char>> gama_tmp_char = gama_char;

                for (int r = r_offset; r < r_offset + 4; r++) {
                    for (int c = c_offset; c < c_offset + 4; c++) {

                        int new_val = gama_int[r][c] + tmp_int[r - r_offset][c - c_offset];
                        if (new_val > 9) {
                            gama_int[r][c] = 9;
                        }
                        else if (new_val < 0) {
                            gama_int[r][c] = 0;
                        }
                        else {
                            gama_int[r][c] = new_val;
                        }
                        if (tmp_char[r - r_offset][c - c_offset] != 'W')
                            gama_char[r][c] = tmp_char[r - r_offset][c - c_offset];
                    }
                }
                dfs(tmp);

                gama_int = gama_tmp_int;
                gama_char = gama_tmp_char;

            }
        }
        tmp.pop_back();
        visited[i] = 0;
    }
}


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    vector<int> tmp_total_ifo;
    dfs(tmp_total_ifo);

    cout << ans << "\n";

    return 0;
}

// 완탐 할 것들,,
// 1. 재료 넣을 순서
// 2. 회전 수
// 3. 재료 넣을 위치