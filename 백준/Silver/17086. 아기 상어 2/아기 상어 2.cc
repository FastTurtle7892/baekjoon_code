#include <iostream>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

int R, C;

int board[51][51];
int visited[51][51];
int dr[8][2] = { {0,1}, {1,0}, {-1,0}, {0,-1}, {-1,-1}, {-1,1 }, {1,1}, {1, -1} };
int safe_dist = 0;
vector<pair<int, int>> memory_one;

void init() {

	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> board[r][c];
			if (board[r][c] == 1) {
				memory_one.push_back({ r,c });
			}
		}
	}
}

void init_visited() {

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			visited[r][c] = 0;
		}
	}
}

int isOutBound(int r, int c) {

	return !(0 <= r && r < R && 0 <= c && c < C);
}

void bfs(int sr, int sc) {

	init_visited();
	queue<pair<int, int>> q;
	q.push({ sr, sc });
	visited[sr][sc] = 1;
	int min_dist = 0;
	while (!q.empty()) {

		int now_r = q.front().first;
		int now_c = q.front().second;

		if (board[now_r][now_c] == 1) {
			min_dist = visited[now_r][now_c] - 1;
			break;
		}
		
		q.pop();

		for (int d = 0; d < 8; d++) {

			int f_r = now_r + dr[d][0];
			int f_c = now_c + dr[d][1];

			if (isOutBound(f_r, f_c)) continue;
			if (visited[f_r][f_c]) continue;

			visited[f_r][f_c] = visited[now_r][now_c] + 1;
			q.push({ f_r, f_c });
		}
	}
	safe_dist = max(safe_dist, min_dist);
}


void process() {

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {	
			if (board[r][c] == 0) {	// 0일때만 확인
				bfs(r, c);
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	process();

	cout << safe_dist << "\n";

	return 0;
}