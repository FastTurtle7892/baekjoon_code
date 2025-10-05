#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;
int main(){
	
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int input; cin >> input;
		pq.push(input);
	}

	for (int i = 0; i < M; i++) {
		long long a = pq.top(); pq.pop();
		long long b = pq.top(); pq.pop();
		pq.push(a + b); pq.push(a + b);
	}
	long long sum = 0;
	while (!pq.empty()) {
		sum += pq.top(); pq.pop();
	}
	cout << sum << "\n";
	return 0;
}

// 1 2 3 4
// 3 3 3 4
// 6 6 3 4 
