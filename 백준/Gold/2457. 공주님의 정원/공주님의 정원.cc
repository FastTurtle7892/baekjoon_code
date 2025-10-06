#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int month_val[13] = { 0, 31, 28 , 31, 30 ,31, 30, 31, 31, 30 ,31, 30 ,31 };

// 31 + 28 + 31 + 30 + 31
// 31 + 28 + 31 + 30 + 31 + 30
// 20 + 31 + 31 + 30 + 31 + 30 + 10

struct Info {

    int sm;
    int sd;
    int em;
    int ed;

    bool operator<(const Info& next) const {    // 무조건 시작 날이 빠른 순으로 정렬

        if (sm > next.sm) return true;
        if (sm < next.sm) return false;

        if (sd > next.sd) return true;
        if (sd < next.sd) return false;

        return false;
    }
};

int now_em = 3;
int now_ed = 1;

int real_em = 12;
int real_ed = 1;

bool cmp(Info a, Info b) {

    if (a.em == b.em) {
        return a.ed > b.ed;
    }
    return a.em > b.em;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    priority_queue<Info>pq;

    int N;  cin >> N;

    Info now;
    for (int i = 0; i < N; i++) {

        cin >> now.sm >> now.sd >> now.em >> now.ed;
        pq.push(now);
    }

    vector<Info> tmp_arr;
    int cnt = 0;
    bool flag = false;

    while (!pq.empty()) {

        while (!pq.empty() && (pq.top().sm < now_em || (pq.top().sm == now_em && pq.top().sd <= now_ed))) {

            tmp_arr.push_back(pq.top()); pq.pop();
        }

        if (!tmp_arr.empty()) {

            sort(tmp_arr.begin(), tmp_arr.end(), cmp);
            now_em = tmp_arr[0].em;
            now_ed = tmp_arr[0].ed;

            tmp_arr.clear();
            cnt++;
        }
        else pq.pop();

        if (now_em == real_em && now_ed >= real_ed) {
            flag = true;
            break;
        }
    }
    if (!flag) cout << 0 << "\n";
    else cout << cnt << "\n";
    return 0;
}

