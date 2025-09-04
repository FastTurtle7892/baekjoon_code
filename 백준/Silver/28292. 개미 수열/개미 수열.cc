#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N;

	if (1 <=  N && N <= 2) {
		cout << 1 << "\n";
	}
	else if (3 <= N && N <= 5) {
		cout << 2 << "\n";
	}
	else {
		cout << 3 << "\n";
	}
	return 0;
}