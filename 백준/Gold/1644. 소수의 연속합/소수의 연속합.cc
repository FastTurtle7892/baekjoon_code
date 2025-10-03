#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int isPrime[4'000'001];
vector<int> arr;
vector<int> sum_arr;
int N;

int ans_cnt = 0;

void init_arr() {

    cin >> N;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) continue;
        for (int j = i * i; j <= N; j += i) {
            isPrime[j] = 1;
        }
    }

    arr.push_back(0);   // 인덱스 1부터 맞추기
    // 1. N보다 작은 소수 모두 arr에 담기
    for (int i = 2; i <= N; i++) {
        if (isPrime[i] == 0) {
            arr.push_back(i);
        }
    }
    // 2. arr로 sum_arr 만들기

    int arr_size = arr.size();
    sum_arr.assign(arr_size, 0);

    for (int i = 1; i < arr_size; i++) {
        sum_arr[i] = arr[i] + sum_arr[i - 1];
    }
}

void process() {

    // 3. start_idx = 0, end_idx = 1로 시작해서 해당되는 누적합 구간 구하기

    int start_idx = 0;
    int end_idx = 1;
    int arr_size = arr.size();

    while (start_idx < arr_size &&  end_idx < arr_size) {

        if (sum_arr[end_idx] - sum_arr[start_idx] < N) {
            end_idx++;
        }
        else if (sum_arr[end_idx] - sum_arr[start_idx] == N) {

            ans_cnt++;
            end_idx++;
        }
        else {
            start_idx++;
        }
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    init_arr();

    process();

    cout << ans_cnt << "\n";

    return 0;
}
