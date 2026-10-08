#include <string>
#include <vector>

using namespace std;

int solution(int n) {

    int ans = 0;
    
    for(int start_int=1; start_int<=n; start_int++) {
        int sum = 0;
        for(int j = start_int; j<=n; j++) {
            sum += j;
            if(sum == n) {
                ans++;
                break;
            }
            else if(sum > n) break;
        }
    }
    return ans;
}