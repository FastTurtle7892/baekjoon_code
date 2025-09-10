#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int arr[101] = { 0, };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;

		if (a == 1) {
			for (int r = b; r <= N; r += b) {
				if (arr[r] == 1) {
					arr[r] = 0;
				}
				else {
					arr[r] = 1;
				}
			}
		}
		else {
		
			int l = b - 1;
			int r = b + 1;
			if (arr[b] == 1) {
				arr[b] = 0;
			}
			else {
				arr[b] = 1;
			}

			while (1 <= l && l <= N && 1 <= r && r <= N && arr[l] == arr[r]) {
				
				if (arr[l] == 0) {
					arr[l] = 1;
				}
				else {
					arr[l] = 0;
				}

				if (arr[r] == 0) {
					arr[r] = 1;
				}
				else {
					arr[r] = 0;
				}

				l -= 1;
				r += 1;
			}
			
		}
	}

	for (int i = 1; i <= N; i++) {

		cout << arr[i];
		if (i % 20 == 0) {
			cout << "\n";
		}
		else {
			cout << " ";
		}
	}
	return 0;

}