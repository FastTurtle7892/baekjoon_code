#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int people_num[11];
int isConnected[11][11];
int N;
int parent[11];
int ans = INT_MAX;



void input() {

	int n, input;
	cin >> N;
	for (int i = 1; i <= N; i++)	// 각 구역에 사람수 입력
		cin >> people_num[i];
	for (int i = 1; i <= N; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> input;
			isConnected[i][input] = 1;	// 연결되어있는 구역 1로 표시.
			isConnected[input][i] = 1;
		}
	}
	for (int i = 1; i <= N; i++)		// 유니온 파인드에 사용할 parent 배열 초기화.
		parent[i] = i;
}

bool BFS(vector<int>& tmp) {

	int visited[11] = { 0, };

	queue<int> q;
	q.push(tmp[0]);
	visited[tmp[0]] = 1;

	while (!q.empty()) {
	
		int now = q.front();
		q.pop();

		for (int i = 0; i < tmp.size(); i++) {
			if (isConnected[now][tmp[i]] == 1 && visited[tmp[i]] == 0) {
				visited[tmp[i]] = 1;
				q.push(tmp[i]);
			}
		}
	}
	for (auto i : tmp) {
		if (visited[i] == 0)
			return false;
	}
	return true;
}

void check_union(vector<int>& A, vector<int>& B) {

	if (A.size() == 0 || B.size() == 0) return;

	if (BFS(A) == true && BFS(B) == true) {

		int A_cnt = 0, B_cnt = 0;
		for (int i = 0; i < A.size(); i++)
			A_cnt += people_num[A[i]];
		for (int i = 0; i < B.size(); i++)
			B_cnt += people_num[B[i]];

		ans = min(ans, abs(A_cnt - B_cnt));
	}
}

void recur(int idx, vector<int> &A, vector<int> &B) {	// 부분집합.

	if (idx > N) {
		// A,B로 나눠졌다면 유니온 파인트 함수 호출
		check_union(A, B);
		return;
	}

	A.push_back(idx);
	recur(idx + 1, A, B);
	A.pop_back();

	B.push_back(idx);
	recur(idx + 1, A, B);
	B.pop_back();
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	input();

	vector<int> A;
	vector<int> B;

	recur(1, A, B);


	if (ans == INT_MAX)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
	return 0;
}