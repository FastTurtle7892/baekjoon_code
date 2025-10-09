#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int p[100'001];

int Find(int x) {

    if (x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void merge(int a, int b) {

    int rootA = Find(a);
    int rootB = Find(b);

    if (rootA == rootB) return;
    if (rootA > rootB) swap(rootA, rootB);

    p[rootB] = rootA;
}

int N, M;
int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        p[i] = i;
    }

    int num1, num2;
    for (int i = 0; i < M; i++) {

        cin >> num1 >> num2;
        
        if (Find(num1) != Find(num2)) {
            merge(num1, num2);
        }
    }

    vector<int> arr;

    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        arr.push_back(input);
    }

    int cnt = 0;
    for (int i = 1; i < N; i++) {

        if (Find(arr[i - 1]) != Find(arr[i])) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}

