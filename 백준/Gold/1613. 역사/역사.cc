#include <iostream>

using namespace std;

int adj[401][401];

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		adj[start][end] = 1;
	}

	for (int k = 1; k <= N; k++) {

		for (int i = 1; i <= N; i++) {

			for (int j = 1; j <= N; j++) {

				if (adj[i][k] == 1 && adj[k][j] == 1)
					adj[i][j] = 1;
			}
		}
	}
	int S; cin >> S;
	for (int i = 0; i < S; i++) {
		cin >> start >> end;
		if (adj[start][end]) cout << -1 << "\n";
		else if (adj[end][start]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}