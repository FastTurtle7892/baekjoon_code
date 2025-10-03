#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int MAX_NUM = 1'000'000;

vector<long long> tree(4 * MAX_NUM + 1, 0);

long long FindCandy(int node, int start, int end, long long val) {

    if (start == end) return start;
    int mid = (start + end) / 2;

    
    if (val <= tree[node * 2])
        return FindCandy(node * 2, start, mid, val);
    else
        return FindCandy(node * 2 + 1, mid + 1, end, val - tree[node * 2]);
}

void update(int node, int start, int end, int idx, long long diff) {

    if (idx < start || end < idx) return;

    if (start == end) {
        if (tree[node] + diff < 0) tree[node] = 0;
        else tree[node] += diff;
        return;
    }
    else {

        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int tp;
    long long num1, num2;
    for (int i = 0; i < N; i++) {

        cin >> tp;

        if (tp == 1) {      // 사탕을 꺼내는 경우.
                
            cin >> num1;    // 꺼낼 사탕의 순위
            int res = FindCandy(1, 1, MAX_NUM, num1);
            update(1, 1, MAX_NUM, res, -1);
            cout << res << "\n";
        }
        else {              // 사탕을 넣는 경우
            cin >> num1 >> num2;    // 넣을 사탕의 맛을 나타내는 정수. 사탕의 개수
            update(1, 1, MAX_NUM, num1, num2);
        }
    }
    return 0;
}
