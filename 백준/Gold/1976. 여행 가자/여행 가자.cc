#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>
#include <set>
#include <map>

using namespace std;

int N, M;

int adj[201][201];
vector<int> vec;

void init() {

	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> adj[r][c];
		}
	}
	int input;
	for (int i = 0; i < M; i++) {
		cin >> input;
		vec.push_back(input);
	}
}

string Floyd() {

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (i == j || i == k || j == k) continue;	
				
				if (adj[i][k] == 1 && adj[k][j] == 1) {
					adj[i][j] = 1;
				}
			}
		}
	}

	for (int i = 1; i < vec.size(); i++) {

		// 출발지와 도착지가 같을때
		if (vec[i - 1] == vec[i]) {

			for (int j = 0; j < N; j++) {

				if (j == vec[i] - 1) continue;		// 자기 자신이면 continue;
				else {
					if (adj[vec[i - 1] - 1][j] == 1 && adj[j][vec[i] - 1] == 1) {
						break;
					}
				}
			}
		}
		else {
			if (adj[vec[i - 1] - 1][vec[i] - 1] == 1) continue;
			else return "NO";
		}
	}
	return "YES";
}




int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	string str = Floyd();

	cout << str << "\n";

	return 0;
}

