#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <iomanip>

using namespace std;

int block_height[257];		// 각 블럭의 높이 개수

int R, C, having_block;

int answer = INT_MAX;
int ans_height = 0;

int min_height = INT_MAX;
int max_height = 0;

void init() {

	cin >> R >> C >> having_block;

	int input;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> input;
			block_height[input]++;
			min_height = min(min_height, input);
			max_height = max(max_height, input);
		}
	}
}

void process() {

	for (int now_h = min_height; now_h <= max_height; now_h++) {

		// 현재 높이보다 낮은 부분을 탐색한다.

		int left_sum = 0;
		for (int left_block = 0; left_block < now_h; left_block++) {

			left_sum += block_height[left_block] * (now_h - left_block);
		}
		int right_sum = 0;
		for (int right_block = now_h + 1; right_block <= max_height; right_block++) {

			right_sum += block_height[right_block] * (right_block - now_h);
		}

		if (having_block + right_sum < left_sum) continue;

		if (answer >= right_sum * 2 + left_sum) {
			answer = right_sum * 2 + left_sum;
			ans_height = now_h;
		}
	}
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();

	process();

	cout << answer << " " << ans_height << "\n";

	return 0;
}