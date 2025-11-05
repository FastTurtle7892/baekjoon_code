#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

vector<string> vec_str;
vector<int> vec_int;
vector<int> info;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string str;
    int num;
    for (int i = 0; i < N; i++) {

        cin >> str >> num;
        vec_str.push_back(str);
        vec_int.push_back(num);
    }

    int input;
    for (int i = 0; i < M; i++) {

        cin >> input;
        int idx = lower_bound(vec_int.begin(), vec_int.end(), input) - vec_int.begin();
        if (idx == N) cout << vec_str[N - 1] << "\n";
        else cout << vec_str[idx] << "\n";
    }

    return 0;
}