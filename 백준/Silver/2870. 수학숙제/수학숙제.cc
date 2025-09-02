#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <string>
#include <climits>

using namespace std;

string str, tmp;

vector<string> vec;

void find_num() {

    while (1) {

        if (tmp.length() > 0 && tmp.front() == '0')
            tmp.erase(tmp.begin());
        else break;
    }
    if (tmp.length() == 0) tmp = '0';
    vec.push_back(tmp);
    tmp = "";
}

bool cmp(string s1, string s2) {
    if (s1.length() == s2.length())
        return s1 < s2;
    return s1.size() < s2.size();
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;


    for (int i = 0; i < N; i++) {
        cin >> str;

        tmp = "";
        
        for (int j = 0; j < str.length(); j++) {
            if (isdigit(str[j])) 
                tmp += str[j];
            else if (!isdigit(str[j]) && tmp.length() > 0)
                find_num();
        }
        if (tmp.length() > 0)
            find_num();

    }
    sort(vec.begin(), vec.end(), cmp);
    for (auto i : vec) cout << i << "\n";
    return 0;
}