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

    vector<int> vec;
    int N, M; cin >> N >> M;

    for (int i = 1; i <= N; i++) vec.push_back(i);
    
    cout << "<";

    int idx = 0;
    for (int i = 0; i < N; i++) {

        idx += (M - 1);
        idx %= vec.size();
        cout << vec[idx];
        if (vec.size() > 1) cout << ", ";
        else cout << ">";
        vec.erase(vec.begin() + idx);
    }
    cout << "\n";
    return 0;
}