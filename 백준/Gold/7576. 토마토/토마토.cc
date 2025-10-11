#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[1001][1001];
int board[1001][1001];
int R, C;
vector<pair<int, int>> start_pos;
int dr[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
int un_tomato_cnt = 0;

void init() {

	cin >> C >> R;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> board[r][c];
			if (board[r][c] == 1) {
				start_pos.push_back({ r,c });
			}
			if (board[r][c] == 0) {
				un_tomato_cnt++;
			}
		}
	}
}

int isOutBound(int r, int c) {
	return !(0 <= r && r < R && 0 <= c && c < C);
}


int process() {

	if (start_pos.empty()) return -1;

	else {

		int max_day = 1;
		queue<pair<int, int>> q;
		for (auto i : start_pos) {
			q.push(i);
			visited[i.first][i.second] = 1;
		}
		while (!q.empty()) {

			int now_r = q.front().first;
			int now_c = q.front().second;

			q.pop();

			for (int d = 0; d < 4; d++) {
				int f_r = now_r + dr[d][0];
				int f_c = now_c + dr[d][1];

				if (isOutBound(f_r, f_c)) continue;
				if (visited[f_r][f_c]) continue;
				if (board[f_r][f_c] == -1) continue;

					un_tomato_cnt--;
					q.push({ f_r, f_c });
					visited[f_r][f_c] = visited[now_r][now_c] + 1;
					max_day = max(max_day, visited[f_r][f_c]);
				
			}
		}

		if (max_day == 1) return 0;
		else if (!un_tomato_cnt) return max_day - 1;
		else return -1;
	}
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	int res = process();

	cout << res << "\n";

	return 0;
}
