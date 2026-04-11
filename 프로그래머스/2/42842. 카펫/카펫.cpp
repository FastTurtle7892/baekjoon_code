#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {

    vector<int> ans;
    int total_cnt = brown + yellow;
    
    for(int i=3; i * i <= total_cnt; i++){
        
        if(total_cnt % i != 0) continue;
        
        else {
            
            int big_val = total_cnt / i;
            int small_val = i;
            
            if(small_val > big_val) swap(big_val, small_val);
            
            if(big_val * 2 + (small_val - 2) * 2 == brown){
                ans.push_back(big_val);
                ans.push_back(small_val);
                break;
            }
            
        }
    }
    return ans;
}

// 12 -> 3 x 4 -> 10, 2
// 9 -> 3 x 3 -> 8, 1