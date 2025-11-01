#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

vector<int> money;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int input;
    for (int i = 0; i < N; i++) {

        cin >> input;
        money.push_back(input);
    }

    int ans = 0;
    int idx = N-1;
    while (M > 0 || idx >= 0) {

        if ((M / money[idx]) > 0) {
            ans += (M / money[idx]);
            M -= (M / money[idx]) * money[idx];
        }
        idx--;
    }
    cout << ans << "\n";

    return 0;
}


