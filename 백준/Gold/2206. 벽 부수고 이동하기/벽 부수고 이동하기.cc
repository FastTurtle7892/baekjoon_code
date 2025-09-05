#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int R, C;
int board[1001][1001];
int dist[1001][1001][2];		// 벽을 부쉈나 안부셨냐?
int dr[4][2] = { {0,1}, { 1,0 },{-1,0 }, {0,-1} };

int min_dist = INT_MAX;

void init() {

	string str;
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		cin >> str;
		for (int c = 0; c < C; c++) {
			board[r][c] = str[c] - '0';
		}
	}
}

struct Info {

	int r;
	int c;
	int isBroke;
	int cost;

	bool operator<(const Info& next) const {
		if (cost > next.cost) return true;
		if (cost < next.cost) return false;
		return false;
	}
};

int isOutBound(int r, int c) {
	return !(0 <= r && r < R && 0 <= c && c < C);
}

int dijkstra() {

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			for (int k = 0;  k < 2; k++) {
				dist[r][c][k] = 21e8;
			}
		}
	}

	priority_queue<Info> pq;
	dist[0][0][0] = 1;
	dist[0][0][1] = 1;
	pq.push({ 0,0,0, 1 });
	pq.push({ 0,0,1, 1 });

	while (!pq.empty()) {

		Info now = pq.top(); pq.pop();

		if (now.r == R - 1 && now.c == C - 1) {
			return dist[now.r][now.c][now.isBroke];
		}

		if (dist[now.r][now.c][now.isBroke] < now.cost) continue;

		for (int d = 0; d < 4; d++) {

			int f_r = now.r + dr[d][0];
			int f_c = now.c + dr[d][1];

			if (isOutBound(f_r, f_c)) continue;
			if (board[f_r][f_c] == 1 && now.isBroke == 0) {

				int nextcost = dist[now.r][now.c][now.isBroke] + 1;

				if (dist[f_r][f_c][1] <= nextcost) continue;

				dist[f_r][f_c][1] = nextcost;
				pq.push({ f_r,f_c,1, nextcost });
			}
			else if (board[f_r][f_c] == 0) {

				int nextcost = dist[now.r][now.c][now.isBroke] + 1;

				if (dist[f_r][f_c][now.isBroke] <= nextcost) continue;

				dist[f_r][f_c][now.isBroke] = nextcost;
				pq.push({ f_r,f_c,now.isBroke, nextcost });
			}
		}
	}
	return -1;
}


int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	int res = dijkstra();

	cout << res << "\n";
	
	return 0;
}
