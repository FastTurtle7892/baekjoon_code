#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    int str1_len = str1.length();
    int str2_len = str2.length();

    int min_val = INT_MAX;
    for (int i = 0; i <= str2_len - str1_len; i++) {

        int tmp_val = 0;
        for (int j = i; j < i + str1_len; j++) {
            if (str1[j - i] != str2[j]) tmp_val++;
        }
        min_val = min(min_val, tmp_val);
    }
    
    cout << min_val << "\n";
    return 0;
}

