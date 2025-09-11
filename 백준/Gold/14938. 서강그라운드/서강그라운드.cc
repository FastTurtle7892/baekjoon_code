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


struct Edge {

	int node;
	int cost;

	bool operator<(const Edge & next) const {

		if (cost > next.cost) return true;
		if (cost < next.cost) return false;
		return false;
	}
};


int answer = 0;
vector<vector<Edge>> adj;
vector<int> dist;
vector<int> item_cnt;

int N, M, R;

void init() {

	cin >> N >> R >> M;

	adj.assign(N + 1, {});
	dist.assign(N + 1, 0);
	item_cnt.assign(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> item_cnt[i];
	}

	// 양방향

	int start, end, cost;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> cost;
		adj[start].push_back({ end, cost });
		adj[end].push_back({ start, cost });
	}
}


void dijkstra(int start_node) {

	for (int i = 1; i <= N; i++) dist[i] = 21e8;

	priority_queue<Edge> pq;
	pq.push({ start_node, 0 });
	dist[start_node] = 0;

	while (!pq.empty()) {

		Edge now = pq.top(); pq.pop();

		if (dist[now.node] < now.cost) continue;

		for (int i = 0; i < adj[now.node].size(); i++) {

			Edge next = adj[now.node][i];

			int nextcost = dist[now.node] + next.cost;

			if (dist[next.node] <= nextcost) continue;

			dist[next.node] = nextcost;
			pq.push({ next.node, nextcost });
		}
	}
	int tmp_sum = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i] != 21e8 && dist[i] <= R) {
			tmp_sum += item_cnt[i];
		}
	}
	answer = max(answer, tmp_sum);
}

void process() {

	for (int i = 1; i <= N; i++) {

		dijkstra(i);
	}
}


int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	process();

	cout << answer << "\n";

	return 0;
}