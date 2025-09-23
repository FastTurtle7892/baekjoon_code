#include <iostream>
#include <cstring>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

int main() {

	int case_num = 1;
	while (1) {
		int L, P, V;
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) break;

		int tmp_num = V / P;
		int total_day = tmp_num * L;
		total_day += min(V - P * tmp_num, L);

		cout << "Case " << case_num <<": " << total_day << "\n";
		case_num++;
	}
	return 0;
}
