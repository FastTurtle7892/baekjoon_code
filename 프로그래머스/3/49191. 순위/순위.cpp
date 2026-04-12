#include <string>
#include <vector>
#include <cstring>

// 1. 플로이드 와샬
// 2. dfs 정방향 간선, 역방향 간선

using namespace std;

int adj[105][105];

int solution(int n, vector<vector<int>> results) {
    
    memset(adj, 0, sizeof(adj));
    for(int i=0; i<results.size(); i++){
        adj[results[i][0]][results[i][1]] =  1;
        adj[results[i][1]][results[i][0]] =  -1;
    }
    
    for(int k=1; k<= n; k++){
        for(int i=1; i<= n; i++){
            for(int j=1; j<=n; j++){
                
                if(adj[i][k] == 1 && adj[k][j] == 1) adj[i][j] = 1;
                if(adj[i][k] == -1 && adj[k][j] == -1) adj[i][j] = -1;
            }
        }
    }
    int ans = 0;
    for(int i=1; i<= n; i++){
        int cnt = 0 ;
        for(int j=1; j<= n ; j++){
            if(adj[i][j] != 0) cnt++;
        }
        if(cnt == n-1) ans++; 
    }
    return ans;
}