#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, V;
	cin >> N >> M >> V;
	vec.assign(N, 0);
	
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}

	int cycle_idx = V - 1;
	int cycle_len = N - cycle_idx;

	for (int i = 0; i < M; i++) {
		int K; cin >> K;

		if (K < cycle_idx) {
			cout << vec[K] << "\n";
		}
		else {

			int diff = (K - cycle_idx) % cycle_len;
			cout << vec[cycle_idx + diff] << "\n";
		}
	}


	return 0;
}
