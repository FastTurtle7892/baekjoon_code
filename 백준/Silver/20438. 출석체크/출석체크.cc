#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int stu[5005];	// 0인 놈만 가능 / 1이면 자고 있다는 뜻
int prefix_sum[5005];
int attend[5005];

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K, Q, M;
	cin >> N >> K >> Q >> M;

	int input;
	for (int i = 0; i < K; i++) {
		cin >> input; stu[input] = 1;
	}
	for (int i = 0; i < Q; i++) {
		cin >> input;
		if (stu[input]) continue;

		else {

			for (int idx = input; idx <= N + 2; idx += input) {
				if (!stu[idx]) attend[idx] = 1;
			}
		}
	}
	for (int idx = 3; idx <= N + 2; idx++) {

		prefix_sum[idx] = prefix_sum[idx - 1] + (attend[idx] ? 1 : 0);
	}

	int start_idx = 0;
	int end_idx = 0;
	for (int i = 0; i < M; i++) {
		cin >> start_idx >> end_idx;
		cout << (end_idx - start_idx + 1) - (prefix_sum[end_idx] - prefix_sum[start_idx - 1]) << "\n";
	}

	return 0;
}

// 3 4 5 6 7 8 9 10 11 12
// 
// 1 1 1 2 2 2 3 3 3 4
// 1 1 2 3 3 3 4 5 5 6
// 
// 
// 
// 3 5 6 9 10 12
// 4 7 8 11