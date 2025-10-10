#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

unordered_set<int> s;

//int check_input(int input) {
//
//	int start_idx = 0;
//	int end_idx = arr.size() - 1;
//
//
//	while (start_idx <= end_idx) {
//
//		int mid = (start_idx + end_idx) / 2;
//
//		if (arr[mid] < input) {
//			start_idx = mid + 1;
//		}
//		else if(arr[mid] > input){
//			end_idx = mid;
//		}
//		else {
//			return 1;
//		}
//	}
//	return 0;
//}

int check_input(int input) {

	if (s.find(input) != s.end()) return 1;
	else return 0;
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		s.insert(input);
	}

	//sort(arr.begin(), arr.end());

	int M; cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> input;
		cout << check_input(input) << "\n";
	}
	return 0;
}