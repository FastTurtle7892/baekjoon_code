#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int R, C, N;
int board[101][101] = { 0, };
int visited[101][101] = { 0, };
int dr[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };


void init() {

	cin >> R >> C >> N;

	int now_r, now_c;
	for (int i = 0; i < N; i++) {
		cin >> now_r >> now_c;
		board[now_r - 1][now_c - 1] = 1;
	}
}

int isOutBound(int r, int c) {
	return !(0 <= r && r < R && 0 <= c && c < C);
}

void init_visited() {

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			visited[r][c] = 0;
		}
	}

}

int bfs(int sr, int sc) {

	init_visited();
	queue<pair<int, int>> q;
	visited[sr][sc] = 1;
	q.push({ sr,sc });

	int cnt = 1;

	while (!q.empty()) {

		int now_r = q.front().first;
		int now_c = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int f_r = now_r + dr[d][0];
			int f_c = now_c + dr[d][1];

			if (isOutBound(f_r, f_c)) continue;
			if (board[f_r][f_c] == 0) continue;
			if (visited[f_r][f_c]) continue;

			cnt++;
			visited[f_r][f_c] = 1;
			q.push({ f_r, f_c });
		}
	}
	return cnt;
}

int process() {

	int max_val = 0;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (board[r][c] == 1) {
				int res = bfs(r, c);
				max_val = max(max_val, res);
			}
		}
	}
	return max_val;
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	int total_res = process();

	cout << total_res << "\n";
	return 0;
}
