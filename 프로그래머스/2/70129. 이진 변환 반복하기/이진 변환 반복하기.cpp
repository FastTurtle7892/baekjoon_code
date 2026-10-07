#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt_zero = 0;

void erase_zero(string &s) {
    
    string new_s;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '0') cnt_zero++;
        else new_s += s[i];
    }
    s = new_s;
}

void cal_two(string &s) {

    string new_s;
    int s_int = s.length();
    
    while (s_int != 1) {
        
        new_s += (s_int % 2) + '0';
        s_int /= 2;
    }
    new_s += '1';
    reverse(new_s.begin(), new_s.end());
    s = new_s;
    
    // 2 7 .. 1
    // 2 3 .. 1
    // 2 1 .. 1
    //   0
    
    // 2 6 .. 0
    // 2 3 .. 1
    // 2 1 .. 1
    // 2 0
    
    // 2 4 .. 0
    // 2 2 .. 0
    //   1 
}


vector<int> solution(string s) {
    
    
    vector<int> answer;
    int cnt = 0;
    
    while(s!= "1") {
        
        erase_zero(s);
        cal_two(s);
        cnt++;
    }
    
    
    answer.push_back(cnt);
    answer.push_back(cnt_zero);
    
    return answer;
}