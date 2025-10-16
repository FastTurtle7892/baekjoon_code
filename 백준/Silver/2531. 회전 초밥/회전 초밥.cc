#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, d, k, c;

vector<int> rest_food;
vector<int> arr;

int ans = 0;
int dist = 0;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> d >> k >> c;
    rest_food.assign(d + 1, 0);
    arr.assign(N, 0);


    for (int i = 0; i < N; i++) {

        cin >> arr[i];
    }
    // 초기 윈도우 설정
    for (int i = 0; i < k; i++) {
        if (rest_food[arr[i]] == 0) dist++;
        rest_food[arr[i]]++;
    }


    ans = dist;
    if (rest_food[c] == 0) ans++;

    for (int i = 0; i < N; i++) {

        int out_food = arr[i];
        rest_food[out_food]--;
        if (rest_food[out_food] == 0) dist--;

        int in_food = arr[(i + k) % N];
        if (rest_food[in_food] == 0) dist++;
        rest_food[in_food]++;

        int tmp = dist;
        if (rest_food[c] == 0) tmp++;
        ans = max(ans, tmp);
    }
    cout << ans << "\n";

    return 0;
}
