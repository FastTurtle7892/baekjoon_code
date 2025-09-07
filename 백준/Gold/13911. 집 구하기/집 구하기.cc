#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

// 멕세권 : 집, 맥도날드 최단 거리가 x이하인 집
// 스세권 : 집, 스타벅스 최단 거리가 y이하인 집

// 구하려는 것 멕세권과 스세권 만족하는 집 중 최단 거리의 합이 최소인 집

// 양방향

// 다익스트라

struct Edge {

	int node;
	long long cost;

	bool operator<(const Edge& next) const {

		if (cost > next.cost) return true;
		if (cost < next.cost) return false;
		return false;
	}
};

int N, M;
long long X, Y;
int MAC_cnt = 0;
int STAR_cnt = 0;


vector<vector<Edge>> adj;
vector<long long> dist1;
vector<long long> dist2;
vector<int> builing_num;

void init() {

	cin >> N >> M;
	adj.assign(N + 3, {});
	dist1.assign(N + 3, 0);
	dist2.assign(N + 3, 0);
	builing_num.assign(N + 3, 0);

	int start, end;
	long long cost;
	for (int i = 0; i < M; i++) {

		cin >> start >> end >> cost;
		adj[start].push_back({ end, cost });
		adj[end].push_back({ start, cost });
	}

	cin >> MAC_cnt >> X;
	int input;
	for (int i = 0; i < MAC_cnt; i++) {
		cin >> input;
		builing_num[input] = 1;
		adj[N + 1].push_back({ input, 0 });
	}

	cin >> STAR_cnt >> Y;
	for (int i = 0; i < STAR_cnt; i++) {
		cin >> input;
		builing_num[input] = 2;
		adj[N + 2].push_back({ input, 0 });
	}
}

void dijkstra(int start_node, vector<long long>& dist) {

	for (int i = 1; i <= N + 2; i++) dist[i] = LLONG_MAX;

	priority_queue<Edge> pq;
	pq.push({ start_node, 0 });
	dist[start_node] = 0;

	while (!pq.empty()) {

		Edge now = pq.top(); pq.pop();

		if (dist[now.node] < now.cost) continue;

		for (int i = 0; i < adj[now.node].size(); i++) {

			Edge next = adj[now.node][i];

			long long nextcost = dist[now.node] + next.cost;

			if (dist[next.node] <= nextcost) continue;

			dist[next.node] = nextcost;
			pq.push({ next.node, nextcost });
		}
	}
}

long long process() {

	long long min_dist = LLONG_MAX;

	dijkstra(N + 1, dist1);
	dijkstra(N + 2, dist2);

	for (int i = 1; i <= N; i++) {

		if (builing_num[i] != 0) continue;

		if (dist1[i] == LLONG_MAX || dist2[i] == LLONG_MAX) continue;
		if (dist1[i] > X || dist2[i] > Y) continue;          // 멕세권/스세권 조건


		min_dist = min(dist1[i] + dist2[i], min_dist);
	}
	if (min_dist != LLONG_MAX) return min_dist;
	else return -1;
}


int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	long long res = process();

	cout << res << "\n";

	return 0;
}