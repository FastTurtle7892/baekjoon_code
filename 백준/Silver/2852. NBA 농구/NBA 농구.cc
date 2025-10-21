#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;


// 초 단위로 변경.
// 분 * 60 + 초 
// 최소값 : 0 
// 최대값 : 47 * 60 + 59

vector<int> tp_store;
vector<int> num_store;
vector<int> num_store2;
int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    int tp; 
    string str;
    for (int i = 0; i < N; i++) {

        cin >> tp >> str;

        tp_store.push_back(tp);

        int total_sec = stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3));
        num_store.push_back(total_sec);

    }
    num_store.push_back(48 * 60);
    for (int j = 1; j < num_store.size(); j++) {
        num_store2.push_back(num_store[j] - num_store[j - 1]);
    }
    int one_cnt = 0;
    int two_cnt = 0;

    int one_time = 0;
    int two_time = 0;
    for (int i = 0; i < N; i++) {

        if (tp_store[i] == 1) {
            
            one_cnt++;
            if (one_cnt > two_cnt)
                one_time += num_store2[i];
            else if (one_cnt < two_cnt)
                two_time += num_store2[i];
        }
        else {
            two_cnt++;
            if (two_cnt > one_cnt)
                two_time += num_store2[i];
            else if (two_cnt < one_cnt)
                one_time += num_store2[i];
        }
    }
    if (0 <= one_time / 60 && one_time / 60 <= 9)
        cout << "0" << one_time/60 << ":";
    else cout << one_time/60 << ":";

    if (0 <= one_time % 60 && one_time % 60 <= 9)
        cout << "0" << one_time % 60;
    else cout << one_time % 60;

    cout << "\n";

    if (0 <= two_time / 60 && two_time / 60 <= 9)
        cout << "0" << two_time / 60 << ":";
    else cout << two_time / 60 << ":";

    if (0 <= two_time % 60 && two_time % 60 <= 9)
        cout << "0" << two_time % 60;
    else cout << two_time % 60;

    cout << "\n";

    return 0;
}