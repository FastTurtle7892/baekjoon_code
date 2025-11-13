#include <iostream>
#include <string>
#include <stack>

using namespace std;

void word_stack(stack<char>& s) {
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    getline(cin, str);

    bool flag = false; 
    stack<char> s;

    for (char c : str) {
        if (c == '<') {
           
            word_stack(s);
            flag = true;
            cout << c; 
        }
        else if (c == '>') {
            flag = false;
            cout << c; 
        }
        else if (flag) {
            
            cout << c;
        }
        else { 
            if (c == ' ') {
                
                word_stack(s);
                cout << ' '; 
            }
            else {
                s.push(c);
            }
        }
    }

    word_stack(s);
    cout << '\n';

    return 0;
}