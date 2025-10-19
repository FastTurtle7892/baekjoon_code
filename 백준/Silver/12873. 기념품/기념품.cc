#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
vector<int> vec;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vec.resize(N);
    iota(vec.begin(), vec.end(), 1);

    int r_num = 1;
    int now_idx = 0;
    while (vec.size() > 1) {
        
        long long steps = static_cast<long long>(pow(r_num, 3));

        int del_idx = (now_idx + steps - 1 + vec.size()) % vec.size();
        vec.erase(vec.begin() + del_idx);
        now_idx = del_idx;
        r_num++;
    }
    cout << vec[0] << "\n";

    return 0;
}