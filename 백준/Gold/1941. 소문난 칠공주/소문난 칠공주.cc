#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

char board[5][5];
int visited[5][5];

int N = 5;

int ans = 0;

int dr[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
set<vector<pair<int, int>>> memory;

void init() {

	string str;
	for (int r = 0; r < N; r++) {
		cin >> str;
		for (int c = 0; c < N; c++) {
			board[r][c] = str[c];
			
		}
	}
}

int isOutBound(int r, int c) {
	return !(0 <= r && r < N && 0 <= c && c < N);
}

void dfs(int r, int c, int cnt_S, int cnt_Y, int rest_cnt, vector<pair<int, int>> vec) {

	if (cnt_S + rest_cnt < 4)
		return;
	
	if (rest_cnt == 0) {

		sort(vec.begin(), vec.end());
		if (memory.find(vec) == memory.end()) {
			ans++;
			memory.insert(vec);
		}
		return;
	}

	for (int i = 0; i < vec.size(); i++) {
		for (int d = 0; d < 4; d++) {

			int f_r = vec[i].first + dr[d][0];
			int f_c = vec[i].second + dr[d][1];

			if (isOutBound(f_r, f_c)) continue;
			if (visited[f_r][f_c]) continue;

			visited[f_r][f_c] = 1;
			vec.push_back({ f_r, f_c });
			if (board[f_r][f_c] == 'S')
				dfs(f_r, f_c, cnt_S + 1, cnt_Y, rest_cnt - 1, vec);
			else
				dfs(f_r, f_c, cnt_S, cnt_Y + 1, rest_cnt - 1, vec);
			visited[f_r][f_c] = 0;
			vec.pop_back();
		}
	}
}

void process() {

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			
			vector<pair<int, int>> vec;
			vec.push_back({ r,c });
			visited[r][c] = 1;
			if (board[r][c] == 'S')
				dfs(r, c, 1, 0, 6, vec);
			else
				dfs(r, c, 0, 1, 6, vec);
			visited[r][c] = 0;
			vec.clear();
		}
	}
}


int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	process();

	cout << ans << "\n";

	return 0;
}