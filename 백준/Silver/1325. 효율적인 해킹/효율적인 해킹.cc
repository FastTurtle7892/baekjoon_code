#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> near_node;
vector<int> visited;
vector<int> answer;

void BFS(int node);

int main() {
	

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, start_node, end_node;
	cin >> N >> M;

	near_node.resize(N + 1);
	visited.resize(N + 1, 0);
	answer.resize(N + 1, 0);

	for (int i = 0; i < M; i++) {

		cin >> start_node >> end_node;
		near_node[start_node].push_back(end_node);
	}

	for (int i = 1; i <= N; i++) {
		
		fill(visited.begin(), visited.end(), 0);
		BFS(i);
	}

	int max = 0;
	for (int i=1; i <= N; i++) {
		if (max < answer[i])
			max = answer[i];
	}

	for (int i = 1; i <= N; i++) {
		if (answer[i] == max)
			cout << i << " ";
	}
}

void BFS(int node) {

	queue<int> q;
	q.push(node);
	visited[node] += 1;

	while (!q.empty()) {

		int now_node = q.front();
		q.pop();

		for (int i : near_node[now_node]) {
			if (!visited[i]) {
				visited[i] += 1;
				answer[i] += 1;
				q.push(i);
			}
		}
	}
}