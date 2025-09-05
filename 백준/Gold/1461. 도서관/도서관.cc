#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec_plus;
vector<int> vec_minus;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, K; cin >> N >> K;

	int input;
	for (int i = 0; i < N; i++) {

		cin >> input;
		if (input > 0) vec_plus.push_back(input);
		else vec_minus.push_back(-input);
	}

	sort(vec_plus.begin(), vec_plus.end());
	sort(vec_minus.begin(), vec_minus.end());

	int total_sum = 0;


	if (vec_plus.size() > 0 && vec_minus.size() > 0 && abs(vec_plus.back()) > abs(vec_minus.back()) || vec_plus.size() > 0 && vec_minus.size() == 0) {

		for (int i = vec_minus.size() - 1; i >= 0; i -= K) {
			total_sum += 2 * vec_minus[i];
		}
		total_sum += vec_plus.back();
		for (int i = vec_plus.size() - 1 - K; i >= 0; i -= K) {
			total_sum += 2 * vec_plus[i];
		}
	}

	else if (vec_plus.size() > 0 && vec_minus.size() > 0 && abs(vec_plus.back()) < abs(vec_minus.back()) || vec_plus.size() == 0 && vec_minus.size() > 0) {

		for (int i = vec_plus.size() - 1; i >= 0; i -= K) {
			total_sum += 2 * vec_plus[i];
		}
		total_sum += vec_minus.back();
		for (int i = vec_minus.size() - 1 - K; i >= 0; i -= K) {
			total_sum += 2 * vec_minus[i];
		}
	}
	
	cout << total_sum << "\n";
	return 0;
}
