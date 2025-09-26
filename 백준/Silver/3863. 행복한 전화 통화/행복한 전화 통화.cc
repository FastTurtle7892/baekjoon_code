#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    vector<pair<int, int>> calls; 

    while (true) {
        if (!(cin >> N >> M)) return 0;    
        if (N == 0 && M == 0) break;

        calls.clear();
        calls.reserve(N);

        for (int i = 0; i < N; ++i) {
            int src, dest, start, dur;
            cin >> src >> dest >> start >> dur;
            calls.push_back({ start, start + dur }); 
        }

        for (int i = 0; i < M; ++i) {
            int q, Q; 
            cin >> q >> Q;
            int cnt = 0;
            int qEnd = q + Q;

            for (auto& c : calls) {
                int s = c.first;
                int e = c.second; 

                if (s < qEnd && q < e) ++cnt;
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}
