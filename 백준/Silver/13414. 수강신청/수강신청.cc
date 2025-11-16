#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> 

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, K; 
    cin >> N >> K;

    unordered_map<string, int> last_click_order;

    for (int i = 0; i < K; i++) {
        string student_id;
        cin >> student_id;

        last_click_order[student_id] = i;
    }


    vector<pair<int, string>> wait_list;

    for (auto const& pair : last_click_order) {

        wait_list.push_back({ pair.second, pair.first });
    }

    sort(wait_list.begin(), wait_list.end());

    int limit = min((int)wait_list.size(), N);
    for (int i = 0; i < limit; i++) {

        cout << wait_list[i].second << "\n";
    }

    return 0;
}