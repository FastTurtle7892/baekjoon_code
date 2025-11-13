#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> arr;
vector<int> visited;

int ans = 0;
int N, K;

void dfs(int cnt, int sum) {

    if (sum < 0) return;

    if (cnt == N) {
        ans++;
        return;
    }
    for (int i = 0; i < N; i++) {

        if (visited[i]) continue;

        visited[i] = 1;
        dfs(cnt+1, sum + arr[i]);
        visited[i] = 0;
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    arr.assign(N, 0);
    visited.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i] -= K;
    }

    dfs(0, 0);

    cout << ans << "\n";
    return 0;
}