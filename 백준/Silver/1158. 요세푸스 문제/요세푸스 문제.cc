#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <deque>

using namespace std;

// std:rotate(first, middle, last)
// middle : 회전 후 새로운 첫번째 원소가 될 위치.

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    deque<int> d;
    int N, M; cin >> N >> M;

    int input;
    for (int i = 1; i <= N; i++) {

        d.push_back(i);
    }
    vector<int> ans;
    while (!d.empty()) {

        rotate(d.begin(), d.begin() + (M - 1) % d.size(), d.end());
        ans.push_back(d.front());
        d.pop_front();
    }
    cout << "<";
    for (int i = 0; i < N; i++) {
        cout << ans[i];
        if (i != N - 1) {
            cout << ", ";
        }
        else cout << ">";
    }
    cout << "\n";
    return 0;
}