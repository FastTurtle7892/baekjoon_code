#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());

	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += abs(i - vec[i-1]);
	}
	cout << sum << "\n";
	return 0;
}