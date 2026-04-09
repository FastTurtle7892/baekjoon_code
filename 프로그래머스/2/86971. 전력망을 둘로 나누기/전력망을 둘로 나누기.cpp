#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

vector<vector<int>> wwires;
vector<vector<int>> graph (101);
int visited[101];

void init_graph(vector<vector<int>> &input){
    
    for(int i=0; i<input.size(); i++){
        graph[input[i][0]].push_back(input[i][1]);   
        graph[input[i][1]].push_back(input[i][0]);   
    }
}

int bfs(int start_node, int edge_idx){
    
    int target_start_node = wwires[edge_idx][0];
    int target_end_node = wwires[edge_idx][1];
    int node_cnt = 1;

    queue<int> q;
    
    visited[start_node] = 1;
    q.push(start_node);
    
    while(!q.empty()){
        
        int now_node = q.front();
        q.pop();
        
        
        for(int i=0; i<graph[now_node].size(); i++){
            
            int next_node = graph[now_node][i];
            
            if(visited[next_node]) continue;
            if(now_node == target_start_node && next_node == target_end_node) continue;
            if(next_node == target_start_node && now_node == target_end_node) continue;
            
            visited[next_node] = 1;
            q.push(next_node);
            node_cnt++;
        }
    }
    return node_cnt;
}

int solution(int n, vector<vector<int>> wires) {

    int min_val = INT_MAX;
    wwires = wires;
    init_graph(wires);  // 간선 저장하기
    
    vector<int> tmp;
    for(int w=0; w<wwires.size(); w++){
        
        tmp.clear();
        memset(visited, 0, sizeof(visited));
        for(int i=1 ; i<=n; i++){
            
            if(!visited[i]) {
                int res = bfs(i,w);
                // cout << res << "\n";
                tmp.push_back(res);     
            }
        }
        // cout << abs(tmp[0] - tmp[1]) << "\n";
        min_val = min(abs(tmp[0] - tmp[1]), min_val);
    }
    return min_val;
}


// 모든 간선을 돌면서 하나씩 끊어서 bfs로 확인한다. 
// bfs할때 넣고 뺄때 그 수가 결국에는 송전탑 수