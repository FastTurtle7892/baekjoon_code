#include <string>
#include <vector>
#include <climits>
using namespace std;

bool check_str(string a, string b){
    
    int cnt = 0;
    for(int i=0; i<a.length(); i++){
        if(a[i] != b[i]){
            cnt++;
            if(cnt >= 2) return false;
        }
    }
    return true;
}

vector<int> visited;
int ans_cnt = INT_MAX;

void dfs(string now_str, string target_str, vector<string> &words, int cnt){
    
    if(now_str == target_str){
        ans_cnt = min(ans_cnt, cnt);
        return;
    }
    for(int i=0; i<visited.size(); i++){
        
        if(!visited[i] && check_str(words[i], now_str)){
            visited[i] = 1;
            dfs(words[i], target_str, words, cnt + 1);
            visited[i] = 0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
 
    visited.assign(words.size(), 0);
    dfs(begin, target, words, 0);
    
    if(ans_cnt == INT_MAX) return 0;
    else return ans_cnt;
}