#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

// {비용, 정점 번호}
vector<pair<int, int>> adj[10005];
//chk[i] : i번째 정점이 최소 신장 트리에 속해있는가?
bool chk[10005];
int cnt = 0;	// 현재 선택된 간선의 수

struct Edge{
	int cost;
	int start;
	int end;

	bool operator>(const Edge &other)const{		// 최소 힙일때만 사용.
		return cost > other.cost;
	} 
};

// tuple<int, int ,int> : {비용, 정점 1, 정점 2}
priority_queue<Edge,vector<Edge>,greater<Edge>> pq;

int V, E;
int ans = 0;		// MST 크기 (간선 COST의 총합)

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E;

	int a, b, cost;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> cost;	
		adj[a].push_back({ cost,b });	// 무방향 간선
		adj[b].push_back({ cost, a });
	}

	chk[1] = 1;
	for (auto nxt : adj[1]) pq.push({ nxt.first, 1, nxt.second });

	while (cnt < V - 1) {		// MST의 간선의 개수 : 정점 - 1 개

		Edge tmp = pq.top(); pq.pop();
		if (chk[tmp.end]) continue;
		ans += tmp.cost;
		chk[tmp.end] = 1;
		cnt++;
		for (auto nxt : adj[tmp.end]) {
			if (!chk[nxt.second]) pq.push({ nxt.first, tmp.end, nxt.second });
		}
	}
	cout << ans;
	return 0;
}