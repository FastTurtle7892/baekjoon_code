#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

vector<string> vec = { "pi", "ka", "chu" };
vector<string> vec2 = { "00", "00", "000" };

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;

	for (int i = 0; i < 3; i++) {

		int a = 0;
		
		while (1) {

			a = str.find(vec[i], a);
			if (a == -1) break;
			str.replace(a, vec[i].size(), vec2[i]);
		}
	}
	for (auto i : str) {
		if (i != '0') {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}
