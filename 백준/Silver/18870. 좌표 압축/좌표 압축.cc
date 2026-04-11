#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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
    input.erase(unique(input.begin(), input.end()), input.end());

    for (int i = 0; i < origin.size(); i++) {

        cout << lower_bound(input.begin(), input.end(), origin[i]) - input.begin() << " ";
        
    }
    cout << "\n";
    return 0;
}