#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    // N이 홀수면 Soomin, 짝수면 Song
    if (N % 2 == 1)
        cout << "Soomin\n";
    else
        cout << "Song\n";

    return 0;
}
