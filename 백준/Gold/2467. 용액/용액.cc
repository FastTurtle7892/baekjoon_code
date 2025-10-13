#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> arr;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int input;
	for (int i = 0; i < N; i++) {

		cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	int num1 = 0;
	int num2 = 0;

	int min_val = INT_MAX;
	for (int i = 0; i < N - 1; i++) {

		int target_num = -arr[i];
		int idx = lower_bound(arr.begin() + i + 1, arr.end(), target_num) - arr.begin();
		if (idx < N) {	// 값을 찾았다면,

			if (min_val > abs(arr[idx] + arr[i])) {
				min_val = abs(arr[idx] + arr[i]);
				num1 = arr[idx];
				num2 = arr[i];
			}
		}
		if (idx - 1 > i) {
			if (min_val > abs(arr[idx - 1] + arr[i])) {
				min_val = abs(arr[idx - 1] + arr[i]);
				num1 = arr[idx - 1];
				num2 = arr[i];
			}
		}
	}

	if (num1 > num2) swap(num1, num2);
	cout << num1 << " " << num2 << "\n";
	return 0;
}