#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

set<string> word_s;

vector<int> solution(int n, vector<string> words) {

    
    int i = 1;
    bool flag = false;
    string prev_word = words[0];
    word_s.insert(prev_word);
    for(i=1; i<words.size(); i++){
        
        if(word_s.find(words[i]) != word_s.end() || prev_word.back() != words[i][0]) {
            flag = true;
            break;
        } 
        
        else if(prev_word.back() == words[i][0]) {
            prev_word = words[i];
            word_s.insert(prev_word);
        }

    }

    if(!flag) return {0,0};
    else{
        return {i % n + 1, i / n + 1};
    }
    
}