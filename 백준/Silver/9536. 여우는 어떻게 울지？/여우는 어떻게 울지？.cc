#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> tmp_tok;
vector<string> tok;
vector<int> visited;

void init() {

	tmp_tok.clear();
	tok.clear();
	visited.clear();
}

void str_tok_process(string str, int tp) {

	int a = 0;
	int b = 0;
	if (tp == 0) {
		while (1) {

			b = str.find(' ', a);
			if (b == -1) break;

			tok.push_back(str.substr(a, b - a));
			a = b + 1;
		}
		tok.push_back(str.substr(a, str.length() - a));
	}

	else {
		while (1) {

			b = str.find(' ', a);
			if (b == -1) break;

			tmp_tok.push_back(str.substr(a, b - a));
			a = b + 1;
		}
		tmp_tok.push_back(str.substr(a, str.length() - a));
	}
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, test_case;
	cin >> T;
	cin.ignore();
	for (test_case = 1; test_case < T + 1; test_case++) {

		init();

		string str;
		getline(cin, str);

		str_tok_process(str, 0);
		visited.assign(tok.size(), 0);

		while (1) {

			getline(cin, str);

			if (str == "what does the fox say?") break;

			str_tok_process(str, 1);

			for (int i = 0; i < tok.size(); i++) {
				if (tok[i] == tmp_tok[2]) {
					visited[i] = 1;
				}
			}
			tmp_tok.clear();
		}

		for (int i = 0; i < tok.size(); i++) {
			if (!visited[i]) cout << tok[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}
