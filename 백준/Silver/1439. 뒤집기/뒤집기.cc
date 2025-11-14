#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string str;

    cin >> str;

    int cnt_0 = 0;
    int idx_0 = 0;

    int cnt_1 = 0;
    int idx_1 = 0;
    while (1) {

        idx_0 = str.find('0', idx_0);
        if (idx_0 == -1) {
            idx_1 = str.find('1', idx_1);
            if (idx_1 == -1) break;
            else {
                while (str[idx_1] == '1') idx_1++;
                cnt_1++;
            }
        }
        else {
            while (str[idx_0] == '0') idx_0++;
            cnt_0++;
        }
    }
    cout << min(cnt_0, cnt_1) << "\n";
    return 0;
}
