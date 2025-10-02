#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> origin;	// 원배열
vector<long long> tree;		// 세그트리 배열
int N, M, K;				// M : 변경 횟수
							// K : 합 횟수

void init_total() {

	cin >> N >> M >> K;
	long long input;

	for (int i = 0; i < N; i++) {
		cin >> input;
		origin.push_back(input);
	}

	//int tree_size = pow(2, round(log(N) / log(2) + 0.5) + 1);
	tree.assign(4*N, 0);
}

long long init(long long node, int start, int end) {

	if (start == end) {
		return tree[node] = origin[start];
	}
	else {

		int mid = (start + end) / 2;
		return tree[node] =  init(node * 2, start, mid)
			+ init(node * 2 + 1, mid + 1, end);
	}
}

long long sum(long long node, int start, int end, int left, int right) {

	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	else {

		int mid = (start + end) / 2;
		return sum(node * 2, start, mid, left, right)
			+ sum(node * 2 + 1, mid + 1, end, left, right);
	}
}

void update(long long node, int start, int end, int idx, long long val) {

	if (idx < start || idx > end) return;
	tree[node] += val;
	if (start != end) {

		int mid = (start + end) / 2;
		update(node * 2, start, mid, idx, val);
		update(node * 2 + 1, mid + 1, end, idx, val);
	}
}



void process() {

	long long tp, num1, num2;

	for(int i=0; i< M + K; i++){

		cin >> tp >> num1 >> num2;
		if (tp == 1) {		// a가 1인 경우 - 수 update

			long long diff = num2 - origin[num1 - 1];
			origin[num1 - 1] = num2;
			update(1, 0, N - 1, num1 - 1, diff);
		}
		else {				// a가 2인 경우 - 구간 합 구하기


			long long res = sum(1, 0, N - 1, num1 - 1, num2 - 1);
			cout << res << "\n";
		}
	}
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init_total();

	init(1, 0, N - 1);

	process();

	return 0;
}