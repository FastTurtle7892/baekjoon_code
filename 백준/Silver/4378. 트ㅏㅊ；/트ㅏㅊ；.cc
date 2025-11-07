#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;


unordered_map<char, char> left_shift = {
    {'W', 'Q'}, {'E', 'W'}, {'R', 'E'}, {'T', 'R'},
    {'Y', 'T'}, {'U', 'Y'}, {'I', 'U'}, {'O', 'I'}, {'P', 'O'},
    {'[', 'P'}, {']', '['}, {'\\', ']'},
    {'S', 'A'}, {'D', 'S'}, {'F', 'D'}, {'G', 'F'}, {'H', 'G'},
    {'J', 'H'}, {'K', 'J'}, {'L', 'K'}, {';', 'L'}, {'\'', ';'},
    {'X', 'Z'}, {'C', 'X'}, {'V', 'C'}, {'B', 'V'}, {'N', 'B'},
    {'M', 'N'}, {',', 'M'}, {'.', ','}, {'/', '.'}, {' ', ' '},
    {'1', '`'}, {'2', '1'}, {'3', '2'}, {'4', '3'}, {'5', '4'},
    {'6', '5'}, {'7', '6'}, {'8', '7'}, {'9', '8'}, {'0', '9'},
    {'-', '0'}, {'=', '-'}
};
int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string str;
    while (getline(cin, str)) {

        for (int i = 0; i < str.length(); i++) {

            if (str[i] == ' ') {
                cout << str[i];
            }
            else {
                cout << left_shift[str[i]];
            }
        }
        cout << "\n";
    }

    return 0;
}
