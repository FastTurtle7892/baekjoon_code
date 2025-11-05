#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> origin;
vector<int> new_vec;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	origin.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> origin[i];
	}
	new_vec.push_back(origin[0]);


	for (int i = 1; i < N; i++) {

		auto idx = upper_bound(new_vec.begin(), new_vec.end(), origin[i]);
		int real_idx = idx - new_vec.begin();

		if (real_idx == new_vec.size()) {

			if(new_vec.back() < origin[i])
				new_vec.push_back(origin[i]);
			// 사이즈가 1보다 클때는 앞자리 확인 후 교체
		}
		else {

			if (new_vec[real_idx - 1] < origin[i]) {
				new_vec[real_idx] = origin[i];
			}
		}
	}
	cout << new_vec.size() << "\n";
	return 0;
}

//7
//7 7 9 2 3 5 2


// 일단 하나 넣고 시작.

// idx가 len이 나올경우 (없는경우) -> 그냥 push_back
// idx가 0이 나올경우 -> 인덱스 0자리 대체
// idx가 0도 아니고 len도 아닐때 -> 대체


// idx가 len이 나올경우
// idx가 len 이하가 나올경우

