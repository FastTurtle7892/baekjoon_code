#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<int, int> m;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M; cin >> N >> M;
    int total_cnt = 0;
    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (m.find(input) == m.end()) {
            m[input] = 1;
            total_cnt++;
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> input;
        if (m.find(input) != m.end()) {
            m[input] = 0;
            total_cnt--;
        }
    }
    cout << total_cnt << "\n";
    
    for (auto i : m) {

        if (i.second) cout << i.first << " ";
    }
    cout << "\n";
    return 0;
}
