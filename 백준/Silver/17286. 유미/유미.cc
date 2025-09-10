#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cmath>
#include <cfloat>

using namespace std;

vector<pair<int, int>> pos;
int visited[3];
int sr, sc;
double answer = DBL_MAX;

void dfs(int cnt, int sr, int sc, double dist) {

	if (cnt == 3) {
		answer = min(answer, dist);
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		double tmp_dist = hypot(double(sr - pos[i].first), double(sc - pos[i].second));
		dfs(cnt + 1, pos[i].first, pos[i].second, dist +tmp_dist);
		visited[i] = 0;
	}
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> sr >> sc;
	
	int r, c;
	for (int i = 0; i < 3; i++) {

		cin >> r >> c;
		pos.push_back({ r,c });
	}
	dfs(0, sr, sc, 0.0);
	cout << (long long)answer << "\n";
	return 0;
	
}