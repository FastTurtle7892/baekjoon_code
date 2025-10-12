#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Info {

	long long odd_cnt;
	long long even_cnt;
};

vector<long long> origin;	// 원배열
vector<Info> tree;			// 세그트리 배열

int N, M;


void init() {

	cin >> N;
	long long input;
	for (int i = 0; i < N; i++) {

		cin >> input;
		origin.push_back(input);
	}
	tree.assign(4 * N, {});
}

Info tree_init(int node, int start, int end) {

	if (start == end) {
		if (origin[start] % 2 == 0) {
			return tree[node] = { 0, 1 };
		}
		else {
			return tree[node] = { 1, 0 };
		}
	}
	else {

		int mid = (start + end) / 2;
		Info left_node = tree_init(node * 2, start, mid);
		Info right_node = tree_init(node * 2 + 1, mid + 1, end);

		return tree[node] = {
			left_node.odd_cnt + right_node.odd_cnt, 
			left_node.even_cnt + right_node.even_cnt
		};
	}
}

Info tree_update(int node, int start, int end, int idx) {

	if (idx < start || end < idx) return tree[node];

	if (start == end) {

		if (origin[start] % 2 == 0) {
			return tree[node] = { 0,1 };
		}
		else {
			return tree[node] = { 1,0 };
		}
	}
	else {
		int mid = (start + end) / 2;
		Info left_node = tree_update(node * 2, start, mid, idx);
		Info right_node = tree_update(node * 2 + 1, mid + 1, end, idx);

		return tree[node] = {
			left_node.odd_cnt + right_node.odd_cnt,
			left_node.even_cnt + right_node.even_cnt
		};
	}
}

Info tree_find(int node, int start, int end, int left, int right) {
	
	if (right < start || end < left) return { 0,0 };

	if (left <= start && end <= right) return tree[node];

	else {

		int mid = (start + end) / 2;
		Info left_node = tree_find(node * 2, start, mid, left, right);
		Info right_node = tree_find(node * 2 + 1, mid + 1, end, left, right);

		return {
			left_node.odd_cnt + right_node.odd_cnt,
			left_node.even_cnt + right_node.even_cnt
		};
	}
}

void process() {

	cin >> M;

	int tp;
	long long A, B;
	for (int i = 0; i < M; i++) {

		cin >> tp >> A >> B;

		if (tp == 1) {

			// update 
			origin[A - 1] = B;
			tree_update(1, 0, N - 1, A - 1);
		}
		else if (tp == 2) {
			// 짝수의 개수
			Info res = tree_find(1, 0, N - 1, A - 1, B - 1);

			cout << res.even_cnt << "\n";
		}
		else {
			// 홀수의 개수
			Info res = tree_find(1, 0, N - 1, A - 1, B - 1);
			cout << res.odd_cnt << "\n";
		}
	}
}


int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	tree_init(1, 0, N-1);

	process();

	return 0;
}
