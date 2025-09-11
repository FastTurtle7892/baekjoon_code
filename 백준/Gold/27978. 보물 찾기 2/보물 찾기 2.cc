#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int R, C;
char board[501][501];
int dist[501][501];
int dr[8][2] = { {-1,0}, {-1,1}, {0,1}, {1,1} ,{1,0}, {1,-1}, {0,-1}, {-1,-1} };
int sr = 0, sc = 0, er = 0, ec = 0;


struct Info {

	int r;
	int c;
	int cost;

	bool operator<(const Info &next) const {
		if (cost > next.cost) return true;
		if (cost < next.cost) return false;
		return false;
	}
};

void init() {

	cin >> R >> C;

	string str;
	for (int r = 0; r < R; r++) {
		cin >> str;
		for (int c = 0; c < C; c++) {
			board[r][c] = str[c];
			if (str[c] == 'K') {
				sr = r; sc = c;
				board[r][c] = '.';
			}
			if (str[c] == '*') {
				er = r; ec = c;
				board[r][c] = '.';
			}
			dist[r][c] = 21e8;
		}
	}
}

int isOutBound(int r, int c) {
	return !(0 <= r && r < R && 0 <= c && c < C);
}

int dijkstra() {

	priority_queue<Info> pq;
	dist[sr][sc] = 0;
	pq.push({ sr,sc, 0 });

	while (!pq.empty()) {
	
		Info now = pq.top(); pq.pop();

		if (dist[now.r][now.c] < now.cost) continue;

		for (int d = 0; d < 8; d++) {

			int f_r = now.r + dr[d][0];
			int f_c = now.c + dr[d][1];
			
			if (isOutBound(f_r, f_c)) continue;
			if (board[f_r][f_c] == '#') continue;

			int new_fuel = 0;
			if (d == 1 || d == 2 || d == 3) {
				new_fuel = 0;
			}
			else {
				new_fuel = 1;
			}
			
			if (dist[f_r][f_c] > dist[now.r][now.c] + new_fuel) {
				dist[f_r][f_c] = dist[now.r][now.c] + new_fuel;

				pq.push({ f_r,f_c, dist[f_r][f_c] });
			}
		}
	}
	if (dist[er][ec] == 21e8) return -1;
	else return dist[er][ec];
}


int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	int res = dijkstra();

	cout << res << "\n";

	return 0;
}