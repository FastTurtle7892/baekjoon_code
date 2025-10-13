#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> arr;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	long long input;
	long long max_val = 0;
	for (int i = 0; i < N; i++) {

		cin >> input;
		arr.push_back(input);
		max_val = max(max_val, input);
	}

	long long left_val = 1;
	long long right_val = max_val;
	long long max_len = 0;
	
	while (left_val <= right_val) {

		long long mid = (left_val + right_val) / 2;

		int now_sum = 0;

		for (int i = 0; i < N; i++) {
			now_sum += arr[i] / mid;
		}

		if (now_sum >= M) {

			max_len = max(max_len, mid);
			left_val = mid + 1;
			
		}
		else {
			right_val = mid - 1;
		}
	}
	cout << max_len << "\n";

	return 0;
}



