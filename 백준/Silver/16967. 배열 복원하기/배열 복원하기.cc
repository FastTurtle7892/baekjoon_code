#include <iostream>

using namespace std;

int board[701][701];
int R, C, X, Y;

void init() {
	
	cin >> R >> C >> X >> Y;
	
	for (int r = 0; r < R + X; r++) {
		for (int c = 0; c < C + Y; c++) {
			cin >> board[r][c];
		}
	}
}

void process() {

	for (int r = X; r < R; r++) {
		for (int c = Y; c < C; c++) {
			board[r][c] -= board[r - X][c - Y];
		}
	}
}

void print_board() {

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << board[r][c] << " ";
		}
		cout << "\n";
	}
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	process();

	print_board();

	return 0;
}

