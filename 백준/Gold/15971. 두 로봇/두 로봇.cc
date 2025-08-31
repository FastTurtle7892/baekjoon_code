#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

int N, S, E;

struct Edge {

    int end;
    int cost;
};

vector<vector<Edge>> adj;
vector<int> visited;

int answer = INT_MAX;

void init() {

    cin >> N >> S >> E;

    adj.assign(N + 1, {});
    visited.assign(N + 1, 0);

    int start, end, cost;
    for (int i = 0; i < N - 1; i++) {

        cin >> start >> end >> cost;
        adj[start].push_back({ end, cost });
        adj[end].push_back({ start, cost });
    }



    answer = INT_MAX;
}

void dfs(int now_node, int end_node, int sum, int max_cost) {

    if (now_node == end_node) {

        answer = min(sum - max_cost, answer);
        return;
    }

    for (int i = 0; i < adj[now_node].size(); i++) {

        Edge now = adj[now_node][i];

        if (visited[now.end]) continue;
            
        int now_max= max(now.cost, max_cost);

        visited[now.end] = 1;
        dfs(now.end, end_node, sum + now.cost, now_max);
        visited[now.end] = 0;
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    init();

    visited[S] = 1;
    dfs(S,E,0, 0);

    cout << answer << "\n";

    return 0;
}