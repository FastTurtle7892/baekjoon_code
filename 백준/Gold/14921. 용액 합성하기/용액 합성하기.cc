#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> arr;

int min_val = INT_MAX;
int ans = 0;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	int input;
	for (int i = 0; i < N; i++) {

		cin >> input;
		arr.push_back(input);
	}

	if (arr.size() == 2) {

		cout << arr[0] + arr[1] << "\n";
		return 0;
	}
	else {
		for (int i = 0; i < N - 1; i++) {

			int now_num = -arr[i];

			int idx = lower_bound(arr.begin() + i + 1, arr.end(), now_num) - arr.begin();

			if (idx < N && min_val > abs(arr[idx] + arr[i])) {

				min_val = abs(arr[idx] + arr[i]);
				ans = arr[idx] + arr[i];
			}
			if (idx - 1 > i && min_val > abs(arr[idx - 1] + arr[i])) {
				min_val = abs(arr[idx - 1] + arr[i]);
				ans = arr[idx - 1] + arr[i];
			}
		}
		cout << ans << "\n";
	}

	return 0;
}