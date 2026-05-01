#include <string>
#include <vector>

using namespace std;

int ans_cnt = 0;

void dfs(vector<int> &numbers, int idx, int sum, int target){
    
    if(idx == numbers.size()){
        if(sum == target){
            ans_cnt++;
        }
        return;
    }
    
    dfs(numbers, idx+1, sum + numbers[idx], target);
    dfs(numbers, idx+1, sum - numbers[idx], target);
}

int solution(vector<int> numbers, int target) {

    dfs(numbers, 0, 0, target);
    return ans_cnt;
}