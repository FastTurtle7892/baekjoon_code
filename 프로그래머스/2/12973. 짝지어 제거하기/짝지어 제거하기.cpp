#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{

    stack<int> ss;
    
    for(int i=0; i<s.length(); i++){
        
        if(ss.empty()) ss.push(s[i]);
        
        else {
            
            if(s[i] == ss.top()) ss.pop();
            else ss.push(s[i]);
        }
    }
    if(ss.empty()) return 1;
    else return 0;
}