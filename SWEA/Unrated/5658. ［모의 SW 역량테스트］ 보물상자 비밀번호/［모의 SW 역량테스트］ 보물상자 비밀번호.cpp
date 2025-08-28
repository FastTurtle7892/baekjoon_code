#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <set>


using namespace std;

int N, K;
string str;
int answer = 0;
vector<int> tok;

void init() {

	tok.clear();
	cin >> N >> K >> str;
	answer = 0;
}

void cal_num(string &str) {

	int res = 0;
	int str_len = str.length();
	for (int i = 0; i < str_len; i++) {

		int tmp_res = 0;
		// 만약에 알파벳인 경우
		if ('A' <= str[i] && str[i] <= 'Z') {
			tmp_res += (str[i] - 'A' + 10);
		}

		else {
			tmp_res += (str[i] - '0');
		}
		res *= 16;
		res += tmp_res;
	}
	tok.push_back(res);
}

void seperate_str(string &tmp) {

	int onestep = N / 4;

	for (int idx = 0; idx < N; idx += onestep) {

		string sub_str = tmp.substr(idx, onestep);
		cal_num(sub_str);
	}
}

void process() {

	int rot = N / 4;

	string tmp = str;
	for (int r = 0; r < rot; r++) {

		seperate_str(tmp);

		char tmp_ch = tmp.back();
		tmp.erase(tmp.begin() + tmp.length()-1);
		tmp.insert(tmp.begin(), tmp_ch);
	}

}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	int T, test_case;
	cin >> T;

	for (test_case = 1; test_case < T + 1; test_case++) {

		init();

		process();

		sort(tok.begin(), tok.end());
		tok.erase(unique(tok.begin(), tok.end()), tok.end());
		sort(tok.begin(), tok.end(), greater<>());
		

		cout << "#" << test_case << " " << tok[K-1] << "\n";
	}

	return 0;
}