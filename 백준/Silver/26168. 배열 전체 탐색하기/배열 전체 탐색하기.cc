#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> vec;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	long long input;
	for (int i = 0; i < N; i++) {
		cin >> input; 
		vec.push_back(input);
	}
	sort(vec.begin(), vec.end());

	int tp = 0;
	long long a, b;
	for (int i = 0; i < M; i++) {

		cin >> tp;
		if (tp == 1) {
			cin >> a;
			cout << N - (lower_bound(vec.begin(), vec.end(), a) - vec.begin()) << "\n";
		}
		else if (tp == 2) {
			cin >> a;
			cout << N - (upper_bound(vec.begin(), vec.end(), a) - vec.begin()) << "\n";
		}
		else {
			cin >> a >> b;
			if (a > b) swap(a, b);
			cout << (upper_bound(vec.begin(), vec.end(), b) - vec.begin()) - (lower_bound(vec.begin(), vec.end(), a) - vec.begin())<< "\n";
		}
	}
	return 0;
}