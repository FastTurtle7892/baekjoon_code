#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    
    vector<int> target;
    string tmp;
    
    for(int i=0; i<s.length(); i++) {
        
        if(s[i] != ' ') tmp += s[i];
        else {
            int tmp_integer = 0;
            if (tmp[0] == '-') {
                tmp_integer = stoi(tmp.substr(1));
                tmp_integer *= -1;
            }
            else {
                tmp_integer = stoi(tmp);
            }
            target.push_back(tmp_integer);
            tmp = "";
        }   
    }
    
    if(tmp.length()) {
        int tmp_integer = 0;
        if (tmp[0] == '-') {
            tmp_integer = stoi(tmp.substr(1));
            tmp_integer *= -1;
        }
        else {
            tmp_integer = stoi(tmp);
        }
        target.push_back(tmp_integer);
    }
    
    
    sort(target.begin(), target.end());
    
    int min_int = target[0];
    int max_int = target.back();
    string min_string = "";
    string max_string = "";
    
    if(min_int < 0) {
        min_string += '-';
        min_int *= -1;    
    }
    min_string += to_string(min_int);
    
    if(max_int < 0) {
        max_string += '-';
        max_int *= -1;    
    }
    max_string += to_string(max_int);
    
    return min_string + " " + max_string;    
}