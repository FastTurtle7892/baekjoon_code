#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 단방향이다.

struct Edge {

	int node;
	int cost;
	int isDead;

	bool operator < (const Edge& next) const {

		if (cost > next.cost) return true;
		if (cost < next.cost) return false;
		return false;
	}

};

int N, M, S, E;
int start_node, end_node, cost;
vector<vector<Edge>> adj;
vector<int> dist;
vector<vector<pair<int, int>>> parents;


void bfs(int E) {
	queue<int> q;
	vector<int> vis(N, 0);
	q.push(E);
	vis[E] = 1;

	while (!q.empty()) {
		int now_node = q.front(); q.pop();

		for (auto& p : parents[now_node]) {
			int prev_node = p.first;
			int edge_idx = p.second;

			// prev_node -> now_node 를 구성한 "그 간선"만 죽임 (O(1))
			adj[prev_node][edge_idx].isDead = 1;

			if (!vis[prev_node]) {
				vis[prev_node] = 1;
				q.push(prev_node);
			}
		}
	}
}

int dijkstra() {

	dist.assign(N, 0);
	parents.assign(N, {});

	for (int i = 0; i < N; i++) {
		dist[i] = 21e8;
	}

	priority_queue<Edge> pq;

	dist[S] = 0;
	pq.push({ S, 0, 0 });

	while (!pq.empty()) {

		Edge now = pq.top(); pq.pop();

		if (dist[now.node] < now.cost) continue;

		for (int i = 0; i < adj[now.node].size(); i++) {

			Edge next = adj[now.node][i];
			int nextcost = dist[now.node] + next.cost;

			if (dist[next.node] < nextcost) continue;

			else if (dist[next.node] == nextcost) {
				parents[next.node].push_back({ now.node, i });
			}
			else {
				parents[next.node].clear();
				parents[next.node].push_back({ now.node, i });
				dist[next.node] = nextcost;
				pq.push({ next.node, nextcost, 0 });
			}
		}
	}

	bfs(E);		// 간선 삭제

	dist.assign(N, 0);
	for (int i = 0; i < N; i++) {
		dist[i] = 21e8;
	}

	dist[S] = 0;
	pq.push({ S, 0, 0 });

	while (!pq.empty()) {

		Edge now = pq.top(); pq.pop();

		if (now.isDead) continue;

		if (dist[now.node] < now.cost) continue;

		for (int i = 0; i < adj[now.node].size(); i++) {

			Edge next = adj[now.node][i];

			if (next.isDead) continue;

			int nextcost = dist[now.node] + next.cost;
			if (dist[next.node] <= nextcost) continue;

			dist[next.node] = nextcost;
			pq.push({ next.node, nextcost, 0 });
		}
	}

	if (dist[E] == 21e8)
		return -1;
	else return dist[E];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (1) {

		adj.clear();

		cin >> N >> M;
		if (N == 0 && M == 0) break;

		adj.assign(N, {});
		cin >> S >> E;

		for (int i = 1; i <= M; i++) {
			cin >> start_node >> end_node >> cost;
			adj[start_node].push_back({ end_node, cost, 0 });
		}

		int res = dijkstra();

		cout << res << "\n";
	}

	return 0;
}