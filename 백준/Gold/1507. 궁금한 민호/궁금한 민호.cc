#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

int adj[21][21];
bool check[21][21];

void init() {

    cin >> N;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> adj[r][c];
        }
    }
}







int print_adj() {

    int sum = 0;
    for (int r = 0; r < N; r++) {
        for (int c = r+1; c < N; c++) {
            if (r == c) continue;
            if (check[r][c] == 0) sum += adj[r][c];
        }
    }
    return sum;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == k || i == j || j == k) continue;
                int tmp_num = adj[i][k] + adj[k][j];

                if (adj[i][j] > tmp_num) {

                    cout << -1 << "\n";
                    return 0;
                }
                else if(adj[i][j] == tmp_num){
                    check[i][j] = check[j][i] = true;
                }
            }
        }
    }

    int res = print_adj();

    cout << res << "\n";

    return 0;
}
