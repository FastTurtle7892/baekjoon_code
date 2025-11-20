#include <iostream>

using namespace std;


int main() {

	int R, C, N;
	cin >> R >> C >> N;

	if (R * C < N) cout << 0 << "\n";
	
	else {

		int dr = 1;

		int sx = 1; int sy = 1;
		int top = 2; int bottom = R;
		int r = C; int l = 1;

		for (int i = 1; i < N; i++) {

			if (dr == 1) {
				sy++;
				if (sy == r) {
					dr = 2;
					r--;
				}
			}
			else if (dr == 2) {
				sx++;
				if (sx == bottom) {
					dr = 3;
					bottom--;
				}
			}
			else if (dr == 3) {
				sy--;
				if (sy == l) {
					dr = 4;
					l++;
				}
			}
			else {
				sx--;
				if (sx == top) {
					dr = 1;
					top++;;
				}
			}
		}
		cout << sx << " " << sy << "\n";
	}
	return 0;
}
