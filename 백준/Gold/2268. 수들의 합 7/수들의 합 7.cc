#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> arr;
vector<long long> tree;
int N, M;

void init() {

    cin >> N >> M;
    arr.assign(N + 1, 0);
    tree.assign(4 * N, 0);
}

long long tree_sum(int node, int start, int end, int left, int right) {

    if (right < start || end < left) return -1;

    if (left <= start && end <= right) return tree[node];

    else {

        int mid = (start + end) / 2;
        long long left_node = tree_sum(node * 2, start, mid, left, right);
        long long right_node = tree_sum(node * 2 + 1, mid + 1, end, left, right);
  
        if (left_node == -1) return right_node;
        else if (right_node == -1) return left_node;
        else return left_node + right_node;
    }
}
long long tree_update(int node, int start, int end, int idx) {

    if (idx < start || end < idx) return tree[node];

    if (start == end) return tree[node] = 1LL * arr[start];

    else {

        int mid = (start + end) / 2;
        return tree[node] = tree_update(node * 2, start, mid, idx)
            + tree_update(node * 2 + 1, mid + 1, end, idx);
    }
}

void process() {

    long long tp, A, B;
    for (int i = 0; i < M; i++) {

        cin >> tp >> A >> B;
        if (tp == 0) {
            if (A > B) swap(A, B);
            long long res = tree_sum(1, 1, N, A, B);
            cout << res << "\n";
        }
        else {


            arr[A] = B;
            tree_update(1, 1, N, A);
        }
    }
}
int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    process();

    return 0;
}
