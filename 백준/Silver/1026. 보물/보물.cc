#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A;
vector<int> B;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	A.assign(N, 0);
	B.assign(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	sort(A.begin(), A.end(), greater<>());
	sort(B.begin(), B.end());

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i] * B[i];
	}
	cout << sum << "\n";
	return 0;
}
