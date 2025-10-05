#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>

using namespace std;

int DAT[26];

void check_str(string str) {

    memset(DAT, 0, sizeof(DAT));
    string tmp = "";
    for (int i = 0; i < str.length(); i++) {

        tmp += str[i];
        DAT[str[i] - 'A']++;
        if (DAT[str[i] - 'A'] == 3) {
            tmp += str[i];
            DAT[str[i] - 'A'] = 0;
            i++;
        }
    }
    if (tmp == str) cout << "OK\n";
    else cout << "FAKE\n";
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        string str; cin >> str;
        check_str(str);
    }
    return 0;
}
