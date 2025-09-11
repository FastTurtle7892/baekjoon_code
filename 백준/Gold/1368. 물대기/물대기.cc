#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Prim

struct Edge {

	int node;
	long long cost;

	bool operator<(const Edge & next) const {

		if (cost > next.cost) return true;
		if (cost < next.cost) return false;
		return false;
	}
};

int N, M;

vector<vector<Edge>> adj;
vector<int> CreateCost;
vector<int> visited;

void init() {

	cin >> N;

	adj.assign(N + 1, {});
	visited.assign(N + 1, 0);
	CreateCost.assign(N + 1, 0);

	for (int i = 1; i <= N; i++) cin >> CreateCost[i];

	int input;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> input;

			if (input == 0) continue;
			else {
				adj[r].push_back({ c, input });
				adj[c].push_back({ r, input });
			}
		}
	}
}

int Prim() {


	int ans = 0;
	priority_queue<Edge> pq;
	
	for (int i = 1; i <= N; i++) pq.push({ i, CreateCost[i] });

	while (!pq.empty()) {

		Edge now = pq.top(); pq.pop();

		if (visited[now.node]) continue;

		visited[now.node] = 1;
		ans += now.cost;

		for (int i = 0; i < adj[now.node].size(); i++) {

			Edge next = adj[now.node][i];

			if (visited[next.node]) continue;
			pq.push(next);
		}
	}
	return ans;
}


int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	// 인접 노드와 잇는게 더 저렴한지? 우물을 파는게 더 저렴한지?

	int res = Prim();

	cout << res << "\n";

	return 0;
}