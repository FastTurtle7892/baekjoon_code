#include <iostream>
#include <cstring>
#include <queue>
#include <climits>
#include <vector>
#include <map>

using namespace std;


int N, M;
vector<vector<int>> vvec;


void init() {

    cin >> N >> M;

    vvec.assign(M + 1, {});

    int input;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input;
            vvec[i].push_back(input);
        }
    }
}

pair<int, int> process() {
    vector<int> cnt_vote(N + 1, 0);

    for (int j = 1; j <= M; j++) cnt_vote[vvec[j][0]]++;

    int top1 = 1, top2 = 1;
    for (int i = 1; i <= N; i++) {
        if (cnt_vote[i] > cnt_vote[top1] || (cnt_vote[i] == cnt_vote[top1] && i < top1))
            top1 = i;
    }
    for (int i = 1; i <= N; i++) {
        if (i == top1) continue;
        if (cnt_vote[i] > cnt_vote[top2] || (i != top1 && cnt_vote[i] == cnt_vote[top2] && i < top2) || top2 == top1)
            top2 = i;
    }

    if (cnt_vote[top1] * 2 > M) return { top1, 1 };

    int a = top1, b = top2;
    int ca = 0, cb = 0;

    for (int j = 1; j <= M; j++) {
        for (int k = 0; k < N; k++) {
            int cand = vvec[j][k];
            if (cand == a) { ca++; break; }
            if (cand == b) { cb++; break; }
        }
    }

    if (ca >= cb) return { a, 2 };  
    else return { b, 2 };
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T, test_case;
    cin >> T;

    for (test_case = 1; test_case < T + 1; test_case++) {

        init();

        pair<int, int> res = process();

        cout << res.first << " " << res.second << "\n";
    }

    return 0;
}
