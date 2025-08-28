#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <map>

using namespace std;

// N 최대값 : 100,000
// 각 칸이 높이 : 1,000,000,000

struct Info {

	long long min_height;
	int idx;
};

int N;

int height[100005];
Info H[4 * 100005];		// 세그트리

Info merge(Info left, Info right) {

	if (left.min_height < right.min_height) return left;	// 더 낮은 높이 선택		
	if (left.min_height > right.min_height) return right;	// 더 낮은 높이 선택		
	
	if (left.idx < right.idx) return left;
	if (left.idx >= right.idx) return right;
}

void make_segtree(int idx, int s, int e) {

	if (s == e) {
		H[idx] = { height[s], s };
		return;
	}

	int mid = (s + e) / 2;
	make_segtree(2 * idx, s, mid);
	make_segtree(2 * idx + 1, mid+1, e);

	// 왼쪽 오른쪽 노드 비교해서 높이 작은 거 저장
	H[idx] = merge(H[idx * 2], H[idx * 2 + 1]);
}

Info query(int idx, int s, int e, int l, int r) {

	if (r < s || l > e) return{LLONG_MAX, INT_MAX};
	if (l <= s && e <= r) return H[idx];
	

	int mid = (s + e) / 2;
	Info left = query(idx * 2, s, mid, l, r);
	Info right = query(idx * 2 + 1, mid +1, e, l, r);
	return merge(left, right);
}

long long recur(int l, int r) {

	if (l > r) return 0;
	Info q = query(1, 0, N - 1, l, r);
	long long h = q.min_height;
	int m = q.idx;

	long long now_rect = h * (r - l + 1);

	long long left = recur(l, m - 1);
	long long right = recur(m + 1, r);

	return max({ now_rect, left, right });
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> height[i];
	}

	// 세그트리 만들기

	make_segtree(1, 0, N - 1);

	// 전체 구간 최대 넓이 구하기 (dfs)

	cout << recur(0, N - 1) << "\n";

	return 0;
}
