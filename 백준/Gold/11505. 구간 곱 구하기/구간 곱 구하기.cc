#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<long long> tree;
int N, M, K;
int VAL = 1'000'000'007;

void init() {

    cin >> N >> M >> K;

    arr.assign(N, 0);
    tree.assign(4 * N, 0);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

long long tree_init(int node, int start, int end) {

    if (start == end) {
        return tree[node] = arr[start];
    }
    else {

        int mid = (start + end) / 2;
        return tree[node] = (tree_init(node * 2, start, mid)
            * tree_init(node * 2 + 1, mid + 1, end)) % VAL;
    }
}

long long tree_update(int node, int start, int end, int idx) {

    if (idx < start || end < idx) {
        return tree[node];
    }

    if (start == end) {
        return tree[node] = arr[start];
    }

    else {

        int mid = (start + end) / 2;
        return tree[node] = (tree_update(node * 2, start, mid, idx)
            * tree_update(node * 2 + 1, mid + 1, end, idx)) % VAL;
    }
}

long long tree_find(int node, int start, int end, int left, int right) {

    if (right < start || end < left) {
        return LLONG_MAX;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    else {

        int mid = (start + end) / 2;
        long long left_node = tree_find(node * 2, start, mid, left, right);
        long long right_node = tree_find(node * 2 + 1, mid + 1, end, left, right);

        if (left_node == LLONG_MAX) return right_node;
        else if (right_node == LLONG_MAX) return left_node;
        else return left_node * right_node % VAL;
    }
}

void process() {

    long long tp, A, B;
    for (int i = 0; i < M + K; i++) {

        cin >> tp >> A >> B;
        if (tp == 1) {

            arr[A - 1] = B;
            tree_update(1, 0, N - 1, A - 1);
        }
        else {

            long long res = tree_find(1, 0, N - 1, A - 1, B - 1);
            cout << res << "\n";
        }
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    tree_init(1, 0, N - 1);

    process();

    return 0;
}