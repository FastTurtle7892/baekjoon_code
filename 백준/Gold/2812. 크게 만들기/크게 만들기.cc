#include <iostream>
#include <queue>
#include <string>
#include <deque>

using namespace std;

deque<char> d;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K;
	string str;
	cin >> N >> K >> str;

	for (int i = 0; i < N; i++) {

		// stack이 비어있으면 넣는다.
		if (d.empty()) {
			d.push_back(str[i]);
		}

		// stack의 top < str[i]
		else if (d.back() < str[i]) {

			while (K > 0 && !d.empty() && d.back() < str[i]) {

				K--;
				d.pop_back();
			}
			d.push_back(str[i]);
		}
		else if (d.back() >= str[i]) {

			d.push_back(str[i]);
		}
	}
	
	while (K > 0) {
		K--;
		d.pop_back();
	}
	string ans = "";

	while (!d.empty()) {
		ans += d.front();
		d.pop_front();
	}

	cout << ans << "\n";
	return 0;
}