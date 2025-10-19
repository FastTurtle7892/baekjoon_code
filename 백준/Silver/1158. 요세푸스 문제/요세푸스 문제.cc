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
    cout << "<";
    while (!d.empty()) {

        rotate(d.begin(), d.begin() + (M - 1) % d.size(), d.end());
        cout << d.front();
        if (d.size() > 1) cout << ", ";
        else cout << ">";

        d.pop_front();
    }
    cout << "\n";
    return 0;
}