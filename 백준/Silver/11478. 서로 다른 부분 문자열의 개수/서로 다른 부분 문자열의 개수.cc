#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s; cin >> s;

    set<string> set_s;

    for (int i = 0; i < s.length(); i++) {

        for (int j = 1; j <= s.length() - i; j++) {

            set_s.insert(s.substr(i, j));
        }
    }
    cout << set_s.size() << "\n";
    return 0;
}