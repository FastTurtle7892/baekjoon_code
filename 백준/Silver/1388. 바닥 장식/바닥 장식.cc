#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> floor(N);
    for (int i = 0; i < N; i++) {
        cin >> floor[i];
    }

    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (floor[i][j] == '-') {
                 if (j == 0 || floor[i][j - 1] != '-') {
                    count++;
                }
            }
        }
    }

    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (floor[i][j] == '|') {
                if (i == 0 || floor[i - 1][j] != '|') {
                    count++;
                }
            }
        }
    }

    cout << count << "\n";

    return 0;
}