#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;

queue<int> q;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	int input;
	while (1) {

		cin >> input;
		if (input == -1) break;

		else if (input == 0) {
			if (q.size()) q.pop();
		}
		else {
			if(q.size() < N)
				q.push(input);
		}
	}

	if (q.empty()) cout << "empty";
	else {
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
	}
	cout << "\n";
	return 0;
}