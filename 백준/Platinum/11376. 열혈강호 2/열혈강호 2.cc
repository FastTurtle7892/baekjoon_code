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

vector<int> cap;
vector<int> people;
vector<vector<int>> adj;
vector<int> visited;
vector<int> match;
int N, K;

int ans = 0;

void init() {

    cin >> N >> K;

   adj.assign(2*(N + 1), {});
    visited.assign(K + 1, 0);
    match.assign(2 * (K + 1), -1);

    int input, M;
    for (int i = 1; i <= N; i++) {
        cin >> M;
        for (int j = 0; j < M; j++) {
            cin >> input;
            adj[i].push_back(input);
            adj[i + N].push_back(input);
        }
    }
}

int DFS(int node) {

    
    for (int i = 0; i < adj[node].size(); i++) {

        int next_node = adj[node][i];
        if (visited[next_node]) continue;
        visited[next_node] = 1;
        if (match[next_node] == -1 || DFS(match[next_node])) {
            match[next_node] = node;
            return true;
        }
    }
    return false;
}

void process() {

    for (int i = 1; i <= 2 * N; i++) {

        fill(visited.begin(), visited.end(), 0);
        if (DFS(i)) ans++;
    }
}

int main() {


    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init();

    process();
        
    cout << ans << "\n";
 
    return 0;
}

