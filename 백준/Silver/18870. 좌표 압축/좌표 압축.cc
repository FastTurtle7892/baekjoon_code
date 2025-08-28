#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <map>

using namespace std;

vector<int> v;
vector<int> v_idx;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;	cin >> N;

	for (int i = 0; i < N; i++) {
		int input; cin >> input;
		v.push_back(input);
	}

	v_idx = v;
	sort(v_idx.begin(), v_idx.end());
	v_idx.erase(unique(v_idx.begin(), v_idx.end()), v_idx.end());

	for (int i = 0; i < v.size(); i++) {

		cout << lower_bound(v_idx.begin(), v_idx.end(), v[i]) - v_idx.begin() << " ";
	}
	cout << "\n";

	return 0;
}

// 이진 탐색 -> 원소 탐색 lower_bound, upper_bound (사용조건 : 오름차순 정렬)

// lower_bound : 찾으려는 key값보다 같거나 큰 숫자가 배열에서 몇번째에 처음 등장?
// upper_bound : 찾으려는 key값을 초과하는 숫자가 배열에서 몇번째에 처음 등장?