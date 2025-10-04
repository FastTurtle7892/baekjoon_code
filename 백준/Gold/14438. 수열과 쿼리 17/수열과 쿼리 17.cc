#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> arr;
vector<int> tree; 
int N, M;

int init_tree(int node, int start, int end) {

    if (start == end) 
        return tree[node] = arr[start]; 

    else {

        int mid = (start + end) / 2;
        int left_val= init_tree(node * 2, start, mid);
        int right_val = init_tree(node * 2 + 1, mid + 1, end);

        return tree[node] = min(left_val, right_val);
    }
}

int update_tree(int node, int start, int end, int idx) {

    if (idx < start || end < idx) return tree[node];

    if (start == end)
        return tree[node] = arr[start];

    else {

        int mid = (start + end) / 2;
        int left_val = update_tree(node * 2, start, mid, idx);
        int right_val = update_tree(node * 2 + 1, mid + 1, end, idx);

        if (left_val > right_val) return tree[node] = right_val;    // 원본 배열기준 작은값이라면 그 인덱스값을 tree에 저장
        else return tree[node] = left_val;  
    }
}

int find_tree(int node, int start, int end, int left, int right) {

    if (end < left || right < start) return INT_MAX;

    if (left <= start && end <= right) return tree[node];

    else {

        int mid = (start + end) / 2;
        int left_val = find_tree(node * 2, start, mid, left, right);
        int right_val = find_tree(node * 2 + 1, mid + 1, end, left, right);

        if (left_val == INT_MAX) return right_val;
        else if (right_val == INT_MAX) return left_val;
        else if (left_val > right_val) return right_val;    // 원본 배열기준 작은값이라면 그 인덱스값을 tree에 저장
        else if (left_val < right_val) return left_val;
        else return min(left_val, right_val);
    }
}

void init() {


    cin >> N;

    int input;
    for (int i = 0; i < N; i++) {

        cin >> input;
        arr.push_back(input);
    }
    tree.assign(4 * N + 1, 0);
    init_tree(1, 0, N - 1);
}

void process() {

    cin >> M;

    int tp, num1, num2;

    for (int i = 0; i < M; i++) {

        cin >> tp >> num1 >> num2;
        
        if (tp == 1) {      // i번째 인덱스 값을 v로 바꾼다.

            arr[num1 - 1] = num2;
            update_tree(1, 0, N - 1, num1 - 1);
        }
        else {              // i번째 인덱스부터 j번째 인덱스까지 크기가 가장 작은 값의 인덱스 출력

            int res = find_tree(1, 0, N - 1, num1 - 1, num2 - 1);
            cout << res << "\n";
        }
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    process();

    return 0;
}
