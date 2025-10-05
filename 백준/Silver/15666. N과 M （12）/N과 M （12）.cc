#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> info;

void combi(int idx, vector<int>& tmp) {
	if (tmp.size() == M) {
		for (auto i : tmp)
			cout << i << " ";
		cout << "\n";
		return;
	}
	for (int i = idx; i < info.size(); i++) {

		tmp.push_back(info[i]);
		combi(i, tmp);
		tmp.pop_back();
	}
}

int main() {
	
	ios::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
	
	cin >> N >> M;
	int input;
	
	for (int i = 0; i < N; i++) {
		cin >> input;
		info.push_back(input);
	}
	sort(info.begin(), info.end());
	info.erase(unique(info.begin(), info.end()), info.end());

	vector<int> tmp;
	combi(0, tmp);

	return 0;
}