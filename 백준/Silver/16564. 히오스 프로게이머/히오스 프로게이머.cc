#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> level_vec;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long N, K;
	cin >> N >> K;
	long long input;
	long long max_v = 0;
	for (int i = 0; i < N; i++) {
		cin >> input;
		level_vec.push_back(input);
		max_v = max(max_v, input);
	}

	long long start_v = 0;
	long long end_v = max_v + K;

	long long mid_v = 0;

	long long ans = 0;

	while (start_v <= end_v) {

		mid_v = (start_v + end_v) / 2;

		long long sum = 0;
		for(int i=0; i< N; i++){
			
			if(mid_v - level_vec[i] > 0)
				sum += (mid_v - level_vec[i]);
		}

		if (sum > K) {

			end_v = mid_v - 1;
			
		}
		else {
			ans = max(ans, mid_v);
			start_v = mid_v + 1;
			
		}
	}
	cout << ans << "\n";
	return 0;
}