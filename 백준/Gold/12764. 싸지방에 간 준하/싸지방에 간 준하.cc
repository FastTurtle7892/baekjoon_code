#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <climits>

using namespace std;

struct room_Info {

    int room_num;
    int end_time;
    int use_cnt;
};

struct cmp1 {
    bool operator() (const room_Info& a, const room_Info& b) const {

        if (a.end_time > b.end_time) return true;
        if (a.end_time < b.end_time) return false;
        return false;
    }
};


struct cmp2 {
    bool operator() (const room_Info& a, const room_Info& b) const {

        if (a.room_num > b.room_num) return true;
        if (a.room_num < b.room_num) return false;
        return false;
    }
};

vector<pair<int, int>> v;

int N;
void init() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        v.push_back({ start, end });
    }
}


int main(void) {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    sort(v.begin(), v.end());

    priority_queue<room_Info, vector<room_Info>, cmp1> pq;
    priority_queue<room_Info, vector<room_Info>, cmp2> pq2;

    int room_number = 1;
    pq.push({ room_number, v[0].second, 1});
    room_number++;


    for (int i = 1; i < v.size(); i++) {

        pair<int, int> now = v[i];

        // 지금 시작(now.first) 시점에 비어 있는 방들을 모두 free 큐로 이동
        while (!pq.empty() && pq.top().end_time <= now.first) { // <= 가 포인트!
            pq2.push(pq.top());
            pq.pop();
        }

        if (pq2.empty()) {
            // 빈 방이 없으니 새 방 발급
            pq.push({ room_number, now.second, 1 });
            room_number++;
        }
        else {
            // 가장 작은 번호의 빈 방 재사용
            room_Info reuse = pq2.top(); pq2.pop();
            reuse.end_time = now.second;
            reuse.use_cnt += 1;
            pq.push(reuse);
        }
    }
    int total_rooms = room_number - 1;

    vector<int> res(total_rooms + 1, 0);

    while (!pq.empty()) {

        room_Info now_info = pq.top(); pq.pop();
        res[now_info.room_num] = now_info.use_cnt;
    }
    while (!pq2.empty()) {
        room_Info x = pq2.top(); pq2.pop();
        res[x.room_num] = x.use_cnt;
    }

    cout << total_rooms << "\n";
    for (int i = 1; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}


