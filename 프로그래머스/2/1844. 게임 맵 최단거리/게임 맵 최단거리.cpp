#include<vector>
#include <queue>
using namespace std;

int dr[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
int R,C;

int isOutBound(int r, int c){
    return !(0 <= r && r < R && 0 <= c && c < C);
}
int solution(vector<vector<int> > maps)
{
    R = maps.size();
    C = maps[0].size();
    vector<vector<int>> visited(R, vector<int>(C,0));
    
    queue<pair<int, int>> q;
    q.push({0,0});
    visited[0][0] = 1;
    
    while(!q.empty()){
        
        int now_r = q.front().first;
        int now_c = q.front().second;
                            
        q.pop();
                            
        for(int d=0; d< 4; d++){
            
            int f_r = now_r + dr[d][0];
            int f_c = now_c + dr[d][1];
            
            if(isOutBound(f_r, f_c)) continue;
            if(maps[f_r][f_c] == 0) continue;
            if(visited[f_r][f_c]) continue;
            
            q.push({f_r, f_c});
            visited[f_r][f_c] = visited[now_r][now_c] + 1;
            
        }               
    }
    if(visited[R-1][C-1] == 0) return -1;
    else return visited[R-1][C-1];
    
}