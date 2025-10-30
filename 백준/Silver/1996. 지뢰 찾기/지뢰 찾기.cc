#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

char board[1001][1001];
int ans[1001][1001];
vector<pair<int, int>> start_pos;
int dr[8][2] = { {0,1}, {1,0}, {-1,0}, {0,-1}, {-1,1}, {1,-1}, {1,1}, {-1,-1} };
int N;

int isOutBound(int r, int c) {
	return !(0 <= r && r < N && 0 <= c && c < N);
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	string str;

	for (int r = 0; r < N; r++) {
		cin >> str;
		for (int c = 0; c < N; c++) {
			board[r][c] = str[c];
			if ('1' <= str[c] && str[c] <= '9') {
				ans[r][c] = -1;
				start_pos.push_back({ r,c });
			}
		}
	}
	for (int i = 0; i < start_pos.size(); i++) {

		int now_r = start_pos[i].first;
		int now_c = start_pos[i].second;

		for (int d = 0; d < 8; d++) {
			int f_r = now_r + dr[d][0];
			int f_c = now_c + dr[d][1];

			if (isOutBound(f_r, f_c)) continue;
			if (ans[f_r][f_c] == -1) continue;

			ans[f_r][f_c] += (board[now_r][now_c] - '0');
		}
	}
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (ans[r][c] == -1) cout << '*';
			else if (ans[r][c] >= 10) cout << 'M';
			else cout << ans[r][c];
		}
		cout << "\n";
	}

	return 0;
}
