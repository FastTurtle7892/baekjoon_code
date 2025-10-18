#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge {

    int node;
    long long cost;
    bool operator < (const Edge& next) const {

        if (cost > next.cost) return true;
        if (cost < next.cost) return false;
        return false;
    }
};

vector<vector<Edge>> adj;
int N, M, K;
vector<int> end_pos;
vector<long long> dist;

void init() {

    cin >> N >> M >> K;
    adj.assign(N + 2, {});
    dist.assign(N + 2, 0);

    int start, end;
    long long cost;
    for (int i = 0; i < M; i++) {
        cin >> start >> end >> cost;
        adj[end].push_back({ start, cost });        // 역방향 간선으로 넣기
    }

    for (int i = 0; i < K; i++) {
        cin >> start;
        end_pos.push_back(start);
        adj[N + 1].push_back({ start, 0 });
    }
}


pair<int, long long> dijsktra(int start_node) {

    for (int i = 1; i <= N; i++) dist[i] = LLONG_MAX;
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

    long long max_dist = 0;
    int max_node = INT_MAX;
    for (int i = 1; i <= N; i++) {

        if (dist[i] == LLONG_MAX) continue;
        if (max_dist < dist[i] || (max_dist == dist[i] && max_node > i)) {
            max_dist = dist[i];
            max_node = i;
        }
    }
    return { max_node, max_dist };
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();
    
    pair<int, long long> res = dijsktra(N + 1);

    cout << res.first << "\n" << res.second << "\n";

    return 0;
}