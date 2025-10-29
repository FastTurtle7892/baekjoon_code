#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

map<int, int> m;
vector<int> total_people;
queue<int> q[200001];

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M; cin >> N >> M;


    total_people.assign(N+1, 0);

    int num;
    for (int i = 1; i <= N; i++) {

        cin >> num;
        int input;
        for (int j = 0; j < num; j++) {
            cin >> input;
            q[input].push(i);
        }
    }

    int input2;
    for (int i = 0; i < M; i++) {
        
        cin >> input2;
        if (!q[input2].empty()) {
            total_people[q[input2].front()]++;
            q[input2].pop();
        }
    }

    for (int i = 1; i <= N; i++)
        cout << total_people[i] << " ";
    cout << "\n";
    return 0;
}


