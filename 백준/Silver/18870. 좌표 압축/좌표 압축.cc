#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> input;
    vector<int> origin;
    origin.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> origin[i];
    }
    input = origin;

    sort(input.begin(), input.end());

    unordered_map<int, int> u_map;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if(u_map.find(input[i]) == u_map.end())
            u_map[input[i]] = cnt++;
    }
    for (auto i : origin) cout << u_map[i] << " ";
    cout << "\n";
}