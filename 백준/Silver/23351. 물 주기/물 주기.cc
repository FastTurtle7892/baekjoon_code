#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> vec;

int N, K, A, B;
int day_cnt = 1;

void find_ans() {


    int now_idx = 0;
    while (1) {

        for (int i = 0; i < A; i++) {
            vec[now_idx] += B;
            now_idx = (now_idx + 1) % N;
        }
        for (int i = 0; i < N; i++) {
            
            vec[i] -= 1;
            if (vec[i] == 0) return;
        }
        
        day_cnt++;
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K >> A >> B;
    vec.assign(N, K);

    find_ans();

    cout << day_cnt << "\n";
    return 0;
}
