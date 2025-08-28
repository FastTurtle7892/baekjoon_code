#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <map>

using namespace std;

int board[11][11];
int N = 10;
vector<int> rest_paper(6);

int ans = 26;

void init() {

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> board[r][c];
		}
	}
	for (int i = 1; i < 6; i++) {
		rest_paper[i] = 5;
	}
}

int isOutBound(int r, int c) {
	return !(0 <= r && r < N && 0 <= c && c < N);
}

int check_rect(int sr, int sc, int len) {

	if (isOutBound(sr + len - 1, sc + len - 1)) return 0;

	for (int r = sr; r < sr + len; r++) {
		for (int c = sc; c < sc + len; c++) {
			if (board[r][c] == 0) return 0;
		}
	}
	return 1;
}

void paint_rect(int sr, int sc, int len, int tp) {

	for (int r = sr; r < sr + len; r++) {
		for (int c = sc; c < sc + len; c++) {
			board[r][c] = tp;
		}
	}
}

void dfs(int now_r, int cnt_paper) {

	if (cnt_paper >= ans) return;		// 가지치기


	for (int r = now_r; r < N; r++) {
		for (int c = 0; c < N; c++) {

			if (board[r][c] == 1) {

				for (int len = 1; len <= 5; len++) {

					if (check_rect(r, c, len) && rest_paper[len] > 0) {

						rest_paper[len] -= 1;
						paint_rect(r, c, len, 0);
						dfs(r, cnt_paper + 1);
						paint_rect(r, c, len, 1);
						rest_paper[len] += 1;
					}
				}
				return;
			}
		}
	}
	// 더이상 종이를 칠 할 곳이 없을때
	if(cnt_paper < 26)
		ans = min(ans, cnt_paper);
	
}

// 처음에 종이가 다 0인지 확인
int first_check() {

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (board[r][c] == 1) return 0;
		}
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	init();

	if (first_check()) 
		ans = 0;

	else {

		dfs(0, 0);
		if (ans == 26) ans = -1;
	}

	cout << ans << "\n";

	return 0;
}
