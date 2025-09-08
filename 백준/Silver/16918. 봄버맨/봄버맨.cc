#include <iostream>
#include <string>

using namespace std;

int R, C, limit_time;
char board[201][201];
int cnt_time[201][201];
int isExplode[201][201];
int dr[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

void init_isExplode() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			isExplode[r][c] = 0;
		}
	}
}

void init() {


	cin >> R >> C >> limit_time;

	string str;
	for (int r = 0; r < R; r++) {
		cin >> str;
		for (int c = 0; c < C; c++) {
			board[r][c] = str[c];
			if (board[r][c] == 'O') {
				cnt_time[r][c] = 3;
			}
		}
	}
}

void set_bomb(int now_time) {

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (board[r][c] == '.') {
				board[r][c] = 'O';
				cnt_time[r][c] = now_time + 3;
			}
		}
	}
}

int isOutBound(int r, int c) {
	return !(0 <= r && r < R && 0 <= c && c < C);
}

void explode_bomb(int now_time) {

	init_isExplode();

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (cnt_time[r][c] == now_time) {
				isExplode[r][c] = 1;
			}
		}
	}
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (isExplode[r][c] == 1) {

				board[r][c] = '.';
				cnt_time[r][c] = 0;
				for (int d = 0; d < 4; d++) {
					int f_r = r + dr[d][0];
					int f_c = c + dr[d][1];

					if (isOutBound(f_r, f_c)) continue;

					board[f_r][f_c] = '.';
					cnt_time[f_r][f_c] = 0;
				}
			}
		}
	}
}


void print_board() {

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << board[r][c];
		}
		cout << "\n";
	}
}


void process() {

	if (limit_time == 1)
		print_board();

	else {

		for (int t = 2; t <= limit_time; t++) {

			if (t % 2 == 0) set_bomb(t);
			else explode_bomb(t);
		}
		print_board();
	}
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	process();



	return 0;
}