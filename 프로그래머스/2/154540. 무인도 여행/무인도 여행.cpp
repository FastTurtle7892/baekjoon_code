#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

vector<string> mmaps;
vector<int> ans;
vector<vector<int>> visited;
int dr[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int R = 0;
int C = 0;

int isOutBound(int r, int c){
    return !(0 <= r && r < R && 0 <= c && c < C);
}

int dfs(int sr, int sc) {

    int sum = mmaps[sr][sc] -'0';
    
    for(int d=0; d<4; d++){

        int f_r = sr + dr[d][0];
        int f_c = sc + dr[d][1];

        if(isOutBound(f_r, f_c)) continue;
        if(mmaps[f_r][f_c] == 'X') continue;
        if(visited[f_r][f_c]) continue;

        visited[f_r][f_c] = 1;
        sum += dfs(f_r,f_c);
        
    }
    return sum;
}

int bfs(int sr, int sc) {
    
    int cnt = mmaps[sr][sc] - '0';
    queue<pair<int, int>> q;
    visited[sr][sc] = 1;
    q.push({sr, sc});
    
    while(!q.empty()) {
        
        int now_r = q.front().first;
        int now_c = q.front().second;
        
        q.pop();
        
        for(int d=0; d<4; d++){
            
            int f_r = now_r + dr[d][0];
            int f_c = now_c + dr[d][1];
            
            if(isOutBound(f_r, f_c)) continue;
            if(mmaps[f_r][f_c] == 'X') continue;
            if(visited[f_r][f_c]) continue;
            
            visited[f_r][f_c] = 1;
            q.push({f_r, f_c});
            cnt += mmaps[f_r][f_c] - '0';
        }
    }
    return cnt;
}


vector<int> solution(vector<string> maps) {

    mmaps = maps;
    C = maps[0].size();
    R = maps.size();
    visited.resize(R, vector<int>(C,0));
    
    for(int r=0; r<R; r++) {
        for(int c=0; c<C; c++) {
            if(!visited[r][c] && mmaps[r][c] != 'X') {
                visited[r][c] = 1;
                ans.push_back(dfs(r,c));
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    if(ans.empty()) return {-1};
    else return ans;
}