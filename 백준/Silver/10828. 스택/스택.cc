#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> stack_vec;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int req_cnt; cin >> req_cnt;

    string str;
    int input;
    for (int i = 0; i < req_cnt; i++) {
        cin >> str;

        if (str == "push") {
            cin >> input;
            stack_vec.push_back(input);
        }
        else if (str == "top") {

            if (stack_vec.size())
                cout << stack_vec.back() << "\n";
            else cout << -1 << "\n";
        }
        else if (str == "size") {
            cout << stack_vec.size() << "\n";
        }
        else if (str == "empty") {
            if (stack_vec.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (str == "pop") {
            if (stack_vec.size()) {
                cout << stack_vec.back() << "\n";
                stack_vec.pop_back();
            }
            else cout << -1 << "\n";
        }
    }
    return 0;
}
