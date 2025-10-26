#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

vector<int> plus_vec;
vector<int> minus_vec;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    int input;
    for(int i=0;i < N; i++){
        cin >> input;
        if (input > 0) plus_vec.push_back(input);
        else minus_vec.push_back(input);
    }

    sort(plus_vec.begin(), plus_vec.end(), greater<int>());
    sort(minus_vec.begin(), minus_vec.end());

    int total_sum = 0;

    int p_idx = 0;
    while (p_idx < plus_vec.size() && p_idx + 1 < plus_vec.size()) {
        if (plus_vec[p_idx] >= 1 && plus_vec[p_idx + 1] == 1) total_sum += plus_vec[p_idx] + plus_vec[p_idx + 1];
        else total_sum += plus_vec[p_idx] * plus_vec[p_idx + 1];
        p_idx += 2;
    }
    if (p_idx == plus_vec.size() - 1) total_sum += plus_vec[p_idx];

    int m_idx = 0;
    while (m_idx < minus_vec.size() && m_idx + 1 < minus_vec.size()) {
        total_sum += minus_vec[m_idx] * minus_vec[m_idx + 1];
        m_idx += 2;
    }
    if (m_idx == minus_vec.size() - 1) total_sum += minus_vec[m_idx];

    cout << total_sum << "\n";
    return 0;
}


