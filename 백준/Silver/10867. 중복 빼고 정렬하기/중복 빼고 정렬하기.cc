#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <string>
#include <set>

using namespace std;

set<int> s;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        s.insert(input);
    }
    for (auto i : s) cout << i << " ";
    cout << "\n";

    return 0;
}
