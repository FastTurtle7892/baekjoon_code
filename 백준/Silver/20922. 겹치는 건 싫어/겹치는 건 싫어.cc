#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int DAT[100001];
vector<int> v;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input; 
		v.push_back(input);
	}

	int s_idx = 0;
	int max_len = 0;

	for (int e_idx = 0; e_idx < N; e_idx++) {

		int x = v[e_idx];

		while (DAT[x] == K) {

			DAT[v[s_idx]]--;
			s_idx++;
		}
		DAT[x]++;

		max_len = max(e_idx - s_idx + 1, max_len);
	}

	cout << max_len << "\n";
	return 0;
}