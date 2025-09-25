#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>
#include <set>
#include <map>

using namespace std;

// 뒤에서부터 접근한다.
// 현재 값을 기준으로 바로왼쪽 값이 더 작다면 
// sum += (현재값 - 왼쪽값)
// 다시 탐색

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> vec;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		vec.push_back(input);
	}

	int max_price = vec.back();
	int ans = 0;

	// 무조건 O(N) 으로 끝내야함.

	for (int i = N - 2; i >= 0; i--) {
		ans = max(ans, (max_price - vec[i]));
		max_price = max(max_price, vec[i]);
	}


	cout << ans << "\n";
	return 0;
}

