#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<pair<int, int> > pos;
//
//3 1
//4 1
//2 4
//3 2

int cal() {

	for (int i = 1; i < pos.size(); i++) {
		if ((pos[i - 1].first == 1 && pos[i].first == 3) ||
			(pos[i - 1].first == 4 && pos[i].first == 1) ||
			(pos[i - 1].first == 2 && pos[i].first == 4) ||
			(pos[i - 1].first == 3 && pos[i].first == 2)) {

			return pos[i - 1].second * pos[i].second;
		}
	}
	return pos[0].second * pos[5].second;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 0; i < 6; i++) {
		int a, b;
		cin >> a >> b;
		pos.push_back({ a, b });
	}

	int max_h = 0, max_w = 0;
	for (int i =0; i< pos.size(); i++){

		if (pos[i].first == 1 || pos[i].first == 2) {
			max_w = max(max_w, pos[i].second);
		}
		else if(pos[i].first == 3 || pos[i].first == 4) {
			max_h = max(max_h, pos[i].second);
		}
	}
	cout << N * (max_h * max_w - cal()) << "\n";
	return 0;
}
