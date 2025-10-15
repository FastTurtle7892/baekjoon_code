#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<char, int> u_map = {

    {'B', 1},
    {'S', 2},
    {'G', 3},
    {'P', 4},
    {'D', 5},
};

vector<string> vec;
vector<string> vec_copy;

bool cmp(string a, string b) {

    if (u_map[a[0]] == u_map[b[0]]) {

        return stoi(a.substr(1)) > stoi(b.substr(1));
    }
    return u_map[a[0]] < u_map[b[0]];
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    string str;
    for (int i = 0; i < N; i++) {

        cin >> str;
        vec.push_back(str);
    }
    vec_copy = vec;
    sort(vec_copy.begin(), vec_copy.end(), cmp);

    vector<string> tmp;
    for (int i = 0; i < N; i++) {

        if (vec[i] != vec_copy[i]) {
            tmp.push_back(vec_copy[i]);
        }
    }
    if (tmp.empty()) cout << "OK\n";
    else {
        sort(tmp.begin(), tmp.end(), cmp);

        cout << "KO\n";
        for (auto i : tmp) cout << i << " ";
        cout << "\n";
    }
    return 0;
}