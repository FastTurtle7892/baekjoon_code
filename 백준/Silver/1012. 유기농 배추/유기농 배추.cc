#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <set>
#include <queue>
#include <cstring>

using namespace std;

int mmap[55][55];
int visited[55][55];
int R, C, T;
int dr[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

void bfs(int r, int c) {

    queue<pair<int, int>> q;
    visited[r][c] = 1;
    q.push({ r,c });

    while (!q.empty()) {
    
        int now_r = q.front().first;
        int now_c = q.front().second;

        q.pop();

        for (int d = 0; d < 4; d++) {

            int f_r = now_r + dr[d][0];
            int f_c = now_c + dr[d][1];

            if (0 > f_r || f_r >= R || 0 > f_c || f_c >= C) continue;

            if (mmap[f_r][f_c] == 0) continue;
            if (visited[f_r][f_c]) continue;

            visited[f_r][f_c] = 1;
            q.push({ f_r,f_c });
        }
    }
}
int find_ans() {

    cin >> R >> C >> T;

    int r_input, c_input;
    memset(mmap, 0, sizeof(mmap));
    memset(visited, 0, sizeof(visited));
    for (int t = 0; t < T; t++) {
        
        cin >> r_input >> c_input;
        mmap[r_input][c_input] = 1;
    }

    int cnt = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {

            if (mmap[r][c] == 1 && visited[r][c] == 0) {
            
                bfs(r, c);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test_case; cin >> test_case;

    for (int tc = 0; tc < test_case; tc++) {

        cout << find_ans() << "\n";
    }
    return 0;
}