#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N), diff(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int i = 0; i < N; ++i) {
        int B;
        cin >> B;
        diff[i] = A[i] - B;
    }

    int ans = 0;
    int prev_pos = 0, prev_neg = 0;

    for (int i = 0; i < N; ++i) {
        int pos = 0, neg = 0;

        if (diff[i] > 0)
            pos = diff[i];
        else
            pos = 0;

        if (diff[i] < 0)
            neg = -diff[i];
        else
            neg = 0;

        if (pos - prev_pos > 0)
            ans += pos - prev_pos;

        if (neg - prev_neg > 0)
            ans += neg - prev_neg;

        prev_pos = pos;
        prev_neg = neg;
    }

    cout << ans << "\n";
    return 0;
}
