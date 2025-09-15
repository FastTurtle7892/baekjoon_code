#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;




int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str;

	int N;
	cin >> N;
	vector<int> cnt;
	for (int i = 0; i < N; i++) {

		int a;
		cin >> a;
		cnt.push_back(a);
	}
	int A, B;
	cin >> A >> B;

	long long sum = N;
	for (auto i : cnt) {

		if (i - A <= 0) {
			continue;
		}

		if ((i - A) % B != 0) {
			sum += (i - A) / B + 1;
		}
		else {
			sum += (i - A) / B;
		}
	}
	cout << sum << "\n";
	return 0;
}