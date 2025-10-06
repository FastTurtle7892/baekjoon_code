#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    int input;
    for (int i = 1; i <= N; i++) {
        cin >> input;

        if ((i % 2 == 0 && input % 2 == 0) || (i % 2 == 1 && input % 2 == 1)) {
            continue;
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}


