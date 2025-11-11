#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <unordered_set>

using namespace std;

int u_map_cnt = 1;
unordered_map<string, int> u_map;

int parent[200'001];
int sz[200'001];

int Find(int x) {

    if (x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void merge(int a, int b) {

    int rootA = Find(a);
    int rootB = Find(b);

    if (rootA == rootB) return;
    else if (sz[rootA] < sz[rootB]) swap(rootA, rootB);
    parent[rootB] = rootA;
    sz[rootA] += sz[rootB];
}


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T, test_case;
    cin >> T;

    int N;

    for (int test_case = 1; test_case < T+1; test_case++) {

        cin >> N;
        string str;
        cin.ignore();

        for (int i = 1; i < 200'001; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
        u_map_cnt = 1;

        for (int i = 0; i < N; i++) {
            getline(cin, str);
            int idx = str.find(' ');
            string str1 = str.substr(0, idx);
            string str2 = str.substr(idx + 1);
            
            if (u_map.find(str1) == u_map.end()) {

                u_map[str1] = u_map_cnt;
                u_map_cnt++;
            }
            if (u_map.find(str2) == u_map.end()) {

                u_map[str2] = u_map_cnt;
                u_map_cnt++;
            }
     
            int num1 = u_map[str1];
            int num2 = u_map[str2];

            merge(num1, num2);
            cout << sz[Find(num1)] << "\n";
        }
        u_map.clear();
    }

    return 0;
}
