#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string >total_ans;

void dfs(vector<vector<string>> &tickets, vector<string> &ans, vector<int> &visited){
    
    if(ans.size() == tickets.size() + 1 && total_ans.size() == 0){
        total_ans = ans;
        return;
    }
    for(int i=0; i<visited.size(); i++){
        if(!visited[i] && ans.back() == tickets[i][0]){
            
            visited[i] = 1;
            ans.push_back(tickets[i][1]);

            dfs(tickets, ans, visited);
            
            visited[i] = 0;
            ans.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
       
    vector<string> ans;
    vector<int> visited(tickets.size(), 0);
    sort(tickets.begin(), tickets.end());
    
    ans.push_back("ICN");
    dfs(tickets, ans, visited);


    return total_ans;
}