#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct Info {

    int num;
    int idx;
};

int N, M;
vector<vector<Info>> vec;

bool cmp(Info a, Info b) {

    if (a.num == b.num) return a.idx < b.idx;
    return a.num < b.num;
}

bool check_world(int w1, int w2) {

    for (int k = 0; k < M; k++) {
        if (vec[w1][k].idx != vec[w2][k].idx || vec[w1][k].num != vec[w2][k].num) {
            return false;
        }
    }
    return true;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


    cin >> N >> M;

    vec.assign(N, {});
    for (int i = 0; i < N; i++) {

        Info now;
        for (int j = 0; j < M; j++) {
            cin >> now.num;
            now.idx = j;
            vec[i].push_back(now);
        }
        sort(vec[i].begin(), vec[i].end(), cmp);

        int rank = 0;
        int prev_val = vec[i][0].num; 
        vec[i][0].num = 0; 

        for (int k = 1; k < M; k++) {
            int cur_val = vec[i][k].num;

            if (cur_val > prev_val) {
                rank++; 
            }
            
            vec[i][k].num = rank; 
            prev_val = cur_val;
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {

        for (int j = i + 1; j < N; j++) {

            if (check_world(i, j)) cnt++;

        }
    }
    cout << cnt << "\n";
    return 0;
}