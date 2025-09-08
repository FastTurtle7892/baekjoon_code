#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

double x, y, c;

double check(double tmp_c) {

	double d1 = sqrt(x * x - tmp_c * tmp_c);
	double d2 = sqrt(y * y - tmp_c * tmp_c);
	return (d1 * d2) / (d1 + d2);
}


int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y >> c;

	double start_val = 0;
	double end_val = min(x, y);

	while (end_val- start_val > 1e-6) {

		double mid_val = (start_val + end_val) / 2.0;
		if (check(mid_val) > c) {
			start_val = mid_val;
		}
		else {
			end_val = mid_val;
		}
	}
	cout << fixed << setprecision(3) << end_val << '\n';

	return 0;
}