#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> 

using namespace std;

int str[5] = { 0x0A, 0x0B, 0x0c, 0x0d, 0x0e };

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    if (N == 0) {
        cout << 0 << "\n";
        return 0;
    }

    string str = "";
    while (N != 0) {

        if (N % -2 == 0) {
            str += '0';
            N /= -2;
        }
        else {
            str += '1';
            // N = 몫 * -2 + 1
            // N - 1 = 몫 * -2
            // 몫 = (N - 1) / -2
            N = (N - 1) / -2;
        }
    }
    reverse(str.begin(), str.end());
    cout << str << "\n";
    return 0;
}