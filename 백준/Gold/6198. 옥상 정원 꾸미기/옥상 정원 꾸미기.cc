#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    vector<int> vec;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        vec.push_back(input);
    }

    stack<pair<int, int>> s;
    s.push({ vec.back(), 1 });
    long long total_sum = 0;

    for (int i = N - 2; i >= 0; i--) {
        int now = vec[i];
        int cnt = 1; 

        while (!s.empty() && s.top().first < now) {
            total_sum += s.top().second;
            cnt += s.top().second;
            s.pop();
        }

        s.push({ now, cnt });
    }
    cout << total_sum << "\n";
    return 0;
}
