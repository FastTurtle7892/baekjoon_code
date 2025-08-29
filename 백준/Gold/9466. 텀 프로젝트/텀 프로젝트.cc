#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
vector<int> student;
vector<int> visited;
vector<int> isGrouped;
int cnt = 0;

void init() {

    cin >> N;
    student.assign(N + 1, 0);
    visited.assign(N + 1, 0);
    isGrouped.assign(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> student[i];
    }
    cnt = 0;
}

void dfs(int now_node) {

    visited[now_node] = 1;

    int next_node = student[now_node];

    if (visited[next_node] == 0) {
        dfs(next_node);
    }

    else if (isGrouped[next_node] == 0) {

        for (int cur = next_node; cur != student[next_node]; next_node = student[next_node]) {
            cnt++;
        }
        cnt++;
    }
    isGrouped[now_node] = 1;
}

void process() {

    for (int i = 1; i <= N; i++) {

        if (!visited[i])
            dfs(i);
    }
}

int main() {

    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T, test_case;
    cin >> T;

    for (test_case = 1; test_case < T + 1; test_case++) {

        init();

        process();

        cout << N - cnt << "\n";
    }
    return 0;
}