#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, int> u_map;
vector<string> vec;



int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str;
	int total_str_cnt = 0;

	while (getline(cin, str)) {

		if (u_map.find(str) == u_map.end()) {
			vec.push_back(str);
			u_map[str] = 1;
		}
		else {
			u_map[str]++;
		}
		total_str_cnt++;
	}

	sort(vec.begin(), vec.end());

	for (auto i : vec) {

		cout << i << " " << fixed << setprecision(4) << (double)u_map[i] / total_str_cnt * 100 << "\n";
	}
	return 0;
}