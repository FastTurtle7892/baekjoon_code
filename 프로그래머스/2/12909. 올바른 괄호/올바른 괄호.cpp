#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s) {
    
    stack<char> s_stack;
    
    for(int i=0; i<s.length(); i++){
        
        // "("이면 push stack에 push
        if(s[i] == '(') s_stack.push(s[i]);
        
        // ")"이면 stack top 값이 "(" 인지 확인한다.
        else if(s[i] == ')') {
            
            if(s_stack.size()) {
                
                char check_top = s_stack.top();
                
                if(check_top == '(') {
                    s_stack.pop();
                }
                else return false;
            }
            // 만약 stack이 비어있거나 ")"이면 바로 false 리턴.
            else return false;
            
        }
    }
    if(s_stack.empty())
        return true;
    else return false;

}