#include <iostream>
#include <queue>

using namespace std;

int R, C, K;
char board[6][6];
int visited[6][6];
int sr = 0, sc = 0, er = 0, ec = 0;
int cnt = 0;
int dr[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

void init() {

	cin >> R >> C >> K;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> board[r][c];
		}
	}
	sr = R - 1; sc = 0;
	er = 0; ec = C - 1;
}

int isOutBound(int r, int c) {
	return !(0 <= r && r < R && 0 <= c && c < C);
}

void dfs(int r, int c, int dist_cnt) {

	if (dist_cnt > K)
		return;

	if (r == er && c == ec && dist_cnt == K) {
		cnt++;
		return;
	}

	for (int d = 0; d < 4; d++) {

		int f_r = r + dr[d][0];
		int f_c = c + dr[d][1];

		if (isOutBound(f_r, f_c)) continue;
		if (visited[f_r][f_c]) continue;
		if (board[f_r][f_c] == 'T') continue;

		visited[f_r][f_c] = 1;
		dfs(f_r, f_c, dist_cnt + 1);
		visited[f_r][f_c] = 0;
	}
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	visited[sr][sc] = 1;
	dfs(sr, sc, 1);

	cout << cnt << "\n";

	return 0;
}