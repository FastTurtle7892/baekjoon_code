#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int board[1500][1500];

int dfs(int sr, int sc, int len) {

	if (len == 2) {

		int ans = 0;
		vector<int> tmp;

		for (int r = sr; r < sr + len; r++) {
			for (int c = sc; c < sc + len; c++) {
				tmp.push_back(board[r][c]);
			}
		}
		sort(tmp.begin(), tmp.end());
		return tmp[1];
	}

	vector<int> tmp2;
	int res1 = dfs(sr, sc, len / 2);
	int res2 = dfs(sr, sc + len / 2, len / 2);
	int res3 = dfs(sr + len / 2, sc, len / 2);
	int res4 = dfs(sr + len / 2, sc + len / 2, len / 2);
	tmp2.push_back(res1);
	tmp2.push_back(res2);
	tmp2.push_back(res3);
	tmp2.push_back(res4);
	sort(tmp2.begin(), tmp2.end());
	return tmp2[1];
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	if (N == 1) cout << board[0][0] << "\n";
	else {
		int res = dfs(0, 0, N);
		cout << res << "\n";
	}
	return 0;
}
