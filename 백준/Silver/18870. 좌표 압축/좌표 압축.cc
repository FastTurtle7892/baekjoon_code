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
map<int, int> m;
vector<int> v_tmp;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;	cin >> N;

	for (int i = 0; i < N; i++) {
		int input; cin >> input;
		v.push_back(input);
	}

	v_tmp = v;
	sort(v_tmp.begin(), v_tmp.end());

	int idx = 0;
	for (int i = 0; i < v_tmp.size(); i++) {
		
		if (m.find(v_tmp[i]) == m.end()) {
			m[v_tmp[i]] = idx;
			idx++;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << m[v[i]] << " ";
	}
	cout << "\n";

	return 0;
}