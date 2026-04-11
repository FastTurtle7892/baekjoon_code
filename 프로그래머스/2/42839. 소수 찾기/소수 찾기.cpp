#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<int> ans;
vector<int> visited;
int nn;

void dfs(int cnt, string tmp, string numbers){
    
    if(cnt > nn) return;
    
    if(tmp != ""){
        
        int now_num = stoi(tmp);
        if(now_num >= 2 && ans.find(now_num) == ans.end()){

            int cnt = 0;
            for(int i=2; i * i <= now_num; i++){
                if(now_num % i == 0) cnt++;
            }
            if(!cnt) ans.insert(now_num);
        }
    }
    for(int i=0; i<visited.size(); i++){
        
        if(!visited[i]){
            
            visited[i]  = 1;
            dfs(cnt + 1, tmp + numbers[i], numbers);
            visited[i] = 0;

        }
    }
}

int solution(string numbers) {

    ans.clear();
    nn = numbers.length();
    visited.assign(nn, 0);
    string tmp = "";
    dfs(0, tmp, numbers);
    
    return ans.size();
    
}