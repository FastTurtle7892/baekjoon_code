#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

vector<long long> vec;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    vec.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin() + 1, vec.end());

    long long now_sum = vec[0];
    for (int i = 1; i < N; i++) {

        if (now_sum > vec[i]) {
            now_sum += vec[i];
        }
        else if (now_sum <= vec[i]){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}

