#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;

unordered_map<int, int> u_map;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int test_case, T, N, M;

    cin >> T;
    for (test_case = 1; test_case < T + 1; test_case++) {

        cin >> N;
        int input;
        for (int i = 0; i < N; i++) {
            cin >> input;
            if (u_map.find(input) == u_map.end()) u_map[input] = 1;
        }
        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> input;
            if (u_map.find(input) != u_map.end()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        u_map.clear();
    }

    return 0;
}
