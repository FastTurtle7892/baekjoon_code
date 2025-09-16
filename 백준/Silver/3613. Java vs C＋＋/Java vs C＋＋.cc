#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

bool success = true;

bool check_str(string str) {

	if (str.length() == 0) return false;
	for (int i = 0; i < str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') return false;
	}
	return true;
}

void c_to_java(string str) {

	if (str[0] == '_' || str.back() == '_') cout << "Error!" << "\n";

	else {
		string ans = "";

		string str_tmp;
		int start_idx = 0;
		int end_idx = 0;
		while (1) {

			int end_idx = str.find('_', start_idx);
			if (end_idx == -1) break;

			str_tmp = str.substr(start_idx, end_idx - start_idx);

			if (check_str(str_tmp)) {
				str_tmp[0] = str_tmp[0] - 'a' + 'A';
				ans += str_tmp;
			}
			else {
				success = false;
				cout << "Error!" << "\n";
				return;
			}
			start_idx = end_idx + 1;
		}
		str_tmp = str.substr(start_idx, str.length() - start_idx);
		if (check_str(str_tmp)) {
			str_tmp[0] = str_tmp[0] - 'a' + 'A';
			ans += str_tmp;
		}
		else {
			success = false;
			cout << "Error!" << "\n";
			return;
		}
		ans[0] = ans[0] - 'A' + 'a';
		if (success) cout << ans << "\n";
	}
}

bool check_str2(string str) {

	for (int i = 0; i < str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') return false;
	}
	return true;
}


void java_to_c(string str) {

	if ('A' <= str[0] && str[0] <= 'Z') {
		success = false;
		cout << "Error!" << "\n";
		return;
	}

	else {
		string ans = "";

		string tmp_str;
		int start_idx = 0;

		for (int i = 0; i < str.length(); i++) {

			if ('A' <= str[i] && str[i] <= 'Z') {

				tmp_str = str.substr(start_idx, i - start_idx);
				if (check_str2(tmp_str)) {

					ans += '_';
					ans += tmp_str;
					str[i] = str[i] - 'A' + 'a';
					start_idx = i;
					i--;
				}
				else {
					success = false;
					return;
				}
			}
		}
		tmp_str = str.substr(start_idx, str.length() - start_idx);
		if (check_str2(tmp_str)) {

			ans += '_';
			ans += tmp_str;
		}
		else {
			success = false;
			return;
		}
		if (success)
		{
			ans.erase(ans.begin());
			cout << ans << "\n";
		}
	}
}

bool check_ans(string str) {

	for (int i = 0; i < str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') return false;
		if (str[i] == '_') return false;
	}
	return true;
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str; cin >> str;

	if (str.find('_') == -1) {		// 자바 -> c 스타일로

		java_to_c(str);
	}
	else {							// c -> 자바 스타일로
		if (check_ans(str)) cout << str << "\n";
		else c_to_java(str);
	}


	return 0;
}

// 문장의 제일 앞에 '_'가 오거나 문장의 제일 뒤에 '_'가 올때
// '_ 뒤에 대문자가 올경우