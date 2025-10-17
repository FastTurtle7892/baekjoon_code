#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> arr;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	arr.assign(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int M; cin >> M;

	int cur_idx = 0;
	while (cur_idx < N && M > 0) {

		int max_val = arr[cur_idx];
		int max_idx = 0;
		int tmp_len = min(N-1, cur_idx + M);
		for (int i = cur_idx; i <= tmp_len; i++) {

			if (max_val < arr[i]) {
				max_val = arr[i];
				max_idx = i;
			}
		}
		int now_idx = max_idx;
		while (now_idx > cur_idx && M > 0) {
			swap(arr[now_idx], arr[now_idx - 1]);
			M--;
			now_idx--;
			if (M == 0) {
				break;
			}
		}
		cur_idx++;
	}
	for (auto i : arr) cout << i << " ";
	cout << "\n";

	return 0;
}

// 14 12 41 33 47

// 