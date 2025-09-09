#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;

int visited[301][301];

int N;
int sr, sc, er, ec;

int dr[8][2] = { {-2,-1}, {-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1, -2}, {-1,-2} };

void init() {

	cin >> N;
	cin >> sr >> sc >> er >> ec;

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {

			visited[r][c] = 0;
		}
	}
}

int isOutBound(int r, int c) {
	return !(0 <= r && r < N && 0 <= c && c < N);
}

int bfs() {

	queue<pair<int, int>> q;
	visited[sr][sc] = 1;
	q.push({ sr, sc });

	while (!q.empty()) {

		int now_r = q.front().first;
		int now_c = q.front().second;

		if (now_r == er && now_c == ec) {
			return visited[now_r][now_c] - 1;
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
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T, test_case;
	cin >> T;

	for (test_case = 1; test_case < T + 1; test_case++) {

		init();

		int res = bfs();

		cout << res << "\n";
	}

	return 0;
}