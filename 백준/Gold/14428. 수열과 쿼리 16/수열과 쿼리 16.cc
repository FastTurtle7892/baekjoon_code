#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> arr;
vector<int> tree; // 해당 구간의 제일 작은 값의 인덱스를 저장.
int N, M;

int init_tree(int node, int start, int end) {

    if (start == end) 
        return tree[node] = start;      // 인덱스 저장

    else {

        int mid = (start + end) / 2;
        int left_idx = init_tree(node * 2, start, mid);
        int right_idx = init_tree(node * 2 + 1, mid + 1, end);

        if (arr[left_idx] > arr[right_idx]) return tree[node] = right_idx;    // 원본 배열기준 작은값이라면 그 인덱스값을 tree에 저장
        else if(arr[left_idx] < arr[right_idx]) return tree[node] = left_idx;
        else return tree[node] = min(left_idx, right_idx);      // 인덱스가 작은것을 넣는다.
        
    }
}

int update_tree(int node, int start, int end, int idx) {

    if (idx < start || end < idx) return tree[node];

    if (start == end)
        return tree[node] = start;      // 인덱스 저장

    else {

        int mid = (start + end) / 2;
        int left_idx = update_tree(node * 2, start, mid, idx);
        int right_idx = update_tree(node * 2 + 1, mid + 1, end, idx);

        if (arr[left_idx] > arr[right_idx]) return tree[node] = right_idx;    // 원본 배열기준 작은값이라면 그 인덱스값을 tree에 저장
        else if (arr[left_idx] < arr[right_idx]) return tree[node] = left_idx;
        else return tree[node] = min(left_idx, right_idx);      
    }
}

int find_tree(int node, int start, int end, int left, int right) {

    if (end < left || right < start) return INT_MAX;

    if (left <= start && end <= right) return tree[node];

    else {

        int mid = (start + end) / 2;
        int left_idx = find_tree(node * 2, start, mid, left, right);
        int right_idx = find_tree(node * 2 + 1, mid + 1, end, left, right);

        if (left_idx == INT_MAX) return right_idx;
        else if (right_idx == INT_MAX) return left_idx;
        else if (arr[left_idx] > arr[right_idx]) return right_idx;    // 원본 배열기준 작은값이라면 그 인덱스값을 tree에 저장
        else if (arr[left_idx] < arr[right_idx]) left_idx;
        else return min(left_idx, right_idx);
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
            cout << res + 1 << "\n";
        }
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    process();

    return 0;
}
