#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;

vector<pair<int, int>> vec;

bool cmp(pair<int, int> a, pair<int, int> b) {

	if (a.second == b.second)
		return a.first < b.first;
	return a.second <b.second;
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;

		vec.push_back({ a,b });
	}
	sort(vec.begin(), vec.end(), cmp);
	for (auto i : vec) cout << i.first << " " << i.second << "\n";

	return 0;
}