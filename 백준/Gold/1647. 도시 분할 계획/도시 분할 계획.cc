#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define MAX_LEN  100'000

using namespace std;

struct Info {

    int start;
    int end;
    int cost;

    bool operator < (const Info& next) const {

        if (cost > next.cost) return true;
        if (cost < next.cost) return false;
        return false;
    }
};

int N, M;

priority_queue<Info> pq;

void init() {

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        
        Info now;
        cin >> now.start >> now.end >> now.cost;
        if (now.start > now.end) swap(now.start, now.end);
        pq.push(now);
    }
}

int p[MAX_LEN + 1];

int Find(int x) {

    if (x == p[x]) return x;
    return p[x] = Find(p[x]);
}

void Merge(int a, int b) {

    int rootA = Find(a);
    int rootB = Find(b);

    if (rootA == rootB) return;

    p[rootB] = rootA;
}

int checkUnion(int a, int b) {

    int rootA = Find(a);
    int rootB = Find(b);

    if (rootA == rootB) return 1;
    else return 0;

}

long long kruskal() {

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        p[i] = i;
    }

    int max_len = 0;
    while (!pq.empty()) {

        Info now = pq.top(); pq.pop();

        if (checkUnion(now.start, now.end) == 0) {

            Merge(now.start, now.end);
            ans += now.cost;
            max_len = max(max_len, now.cost);
        }
    }
    return ans - max_len;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    long long res = kruskal();

    cout << res << "\n";

    return 0;
}


