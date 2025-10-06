#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

#define MAX_LEN 1000000

using namespace std;

// 유니온 파인드

int N;

int p[MAX_LEN + 1];
int sz[MAX_LEN + 1];

void init_p() {

    for (int i = 1; i <= MAX_LEN; i++) {
        p[i] = i;
        sz[i] = 1;
    }
}

int Find(int x) {

    if (x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Merge(int a, int b) {

    int rootA = Find(a);
    int rootB = Find(b);

    if (rootA == rootB) return;
    if (sz[rootA] < sz[rootB]) swap(rootA, rootB);
    
    p[rootB] = rootA;
    sz[rootA]+= sz[rootB];
}

void init() {

    cin >> N;

    init_p();

    char tp;
    int num1, num2;
    for (int i = 0; i < N; i++) {

        cin >> tp;
        if (tp == 'I') {

            cin >> num1 >> num2;
            Merge(num1, num2);
        }
        else if(tp == 'Q'){
            cin >> num1;
            cout << sz[Find(num1)] << "\n";
        }
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    return 0;
}

