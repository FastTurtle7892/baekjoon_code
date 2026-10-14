#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {

    vector<set<int>> dp;
    dp.assign(9, {}); // 최소값이 8보다 크면 -1 return
    // 따라서, dp는 인덱스 8까지만 구하면 됨.
    
    int each_first_num = 0;
    for(int i=1; i<= 8; i++) {
        each_first_num = each_first_num * 10 + N;
        dp[i].insert(each_first_num);   // 5, 55, 555 ...
        
        // dp[j] 랑 dp[i-j]가 조합이 되어서 d[i] 가 되는 것임으로
        
        for(int j=1; j<i; j++) {
            for(auto a : dp[j]) {
                for(auto b : dp[i-j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if(b != 0) dp[i].insert(a / b);
                }
            }
        }
        if(dp[i].find(number) != dp[i].end()) return i;
    }
    return -1;
}