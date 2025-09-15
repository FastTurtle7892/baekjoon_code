#include <iostream>
#include <string>
#include <vector>
using namespace std;

int DAT[26] = {
   3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    vector<int> arr;
    for (int i = 0; i < str1.size(); i++) {
        arr.push_back(DAT[str1[i] - 'A']);
        arr.push_back(DAT[str2[i] - 'A']);
    }

    while (arr.size() > 2) {
        vector<int> next;
        for (int i = 0; i < arr.size() - 1; i++) {
            next.push_back((arr[i] + arr[i + 1]) % 10);  
        }
        arr = next;
    }

    cout << arr[0] << arr[1] << "\n";
    return 0;
}
