#include <iostream>
#include <queue>
#include <iomanip>

#define MAX_LEN 1200
using namespace std;

//int board[5][5] = {
//    {00, 00, 09, 10, 11},
//    {00, 08, 02, 03, 12},
//    {19, 07, 01, 04, 13},
//    {18, 06, 05, 14, 00},
//    {17, 16, 15, 00, 00}
//};

int board[MAX_LEN][MAX_LEN];
int visited[MAX_LEN][MAX_LEN];
pair<int, int> path[MAX_LEN][MAX_LEN];

int S, E;
int sr, sc, er, ec;
vector<int> path_memory;

int dr_draw[6][2] = { {-1, 1}, {0, 1}, {1, 0}, {1, -1}, {0, -1}, {-1 ,0} };
int dr_6[6][2] = { {-1,0}, {-1,1}, {0,1}, {1,0}, {1,-1}, {0,-1} };

int isOutBound(int r, int c) {
	return !(0 <= r && r < MAX_LEN && 0 <= c && c < MAX_LEN);
}

void init_board(int S, int E) {

	int now_r = MAX_LEN / 2;
	int now_c = MAX_LEN / 2;

	int now_num = 1;

	board[now_r][now_c] = now_num;
	now_c -= 1;
	int now_step = 1;

	if (now_num == S) { sr = now_r; sc = now_c; }
	if (now_num == E) { er = now_r; ec = now_c; }

	path[now_r][now_c] = { -1, -1 };

	while (now_num <= 1000000) {

		for (int d = 0; d < 6; d++) {

			for (int step = 1; step <= now_step; step++) {

				int f_r = now_r + dr_draw[d][0];
				int f_c = now_c + dr_draw[d][1];

				if (isOutBound(f_r, f_c)) return;

				now_num++;
				board[f_r][f_c] = now_num;
				path[f_r][f_c] = { -1, -1 };

				if (board[f_r][f_c] == S) {
					sr = f_r; sc = f_c;
				}
				if (board[f_r][f_c] == E) {
					er = f_r; ec = f_c;
				}
				now_r = f_r; now_c = f_c;
			}
		}
		now_c -= 1;
		now_step++;
	}
}



void init() {

	cin >> S >> E;
	init_board(S, E);
}


void bfs() {

	queue<pair<int, int>> q;
	q.push({ sr, sc });
	visited[sr][sc] = 1;

	while (!q.empty()) {

		int now_r = q.front().first;
		int now_c = q.front().second;

		if (now_r == er && now_c == ec) {

			// 경로 복원.

			pair<int, int> now_pos = { now_r, now_c };
			path_memory.push_back(board[now_r][now_c]);

			while (now_pos != make_pair(sr, sc)) {

				now_pos = path[now_pos.first][now_pos.second];
				path_memory.push_back(board[now_pos.first][now_pos.second]);
			}
			for (int i = path_memory.size() - 1; i >= 0; i--) {
				cout << path_memory[i] << " ";
			}
			cout << "\n";

			return;
		}

		q.pop();
		for (int d = 0; d < 6; d++) {

			int f_r = now_r + dr_6[d][0];
			int f_c = now_c + dr_6[d][1];

			if (isOutBound(f_r, f_c)) continue;
			if (board[f_r][f_c] == 0) continue;
			if (visited[f_r][f_c]) continue;

			path[f_r][f_c] = { now_r,now_c };
			q.push({ f_r,f_c });
			visited[f_r][f_c] = visited[now_r][now_c] + 1;
		}
	}
}
void print_board() {

	for (int r = 495; r < 505; r++) {
		for (int c = 495; c < 505; c++) {
			cout << setw(3) << board[r][c] << " ";
		}
		cout << "\n";
	}
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	bfs();

	//print_board();

	return 0;
}