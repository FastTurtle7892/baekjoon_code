#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int N;


int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int input;
	for(int i=0; i<N; i++){
		cin >> input;
		arr.push_back(input);
	}

	vector<int> ans(N, 0);

	for (int i = 0; i < N; i++) {

		int cnt_blank = 0;
		int idx = 0;
		while (idx < N) {

			if (ans[idx] == 0) {
				if (cnt_blank == arr[i]) {
					ans[idx] = i + 1;
					break;
				}
				cnt_blank++;
			}
			idx++;
		}
	}
	for (auto i : ans) cout << i << " ";
	cout << "\n";

	return 0;
}
