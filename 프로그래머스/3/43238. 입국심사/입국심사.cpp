#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {

    long long ans = 0;
    long long left = 1;
    long long right = (long long)n * *max_element(times.begin(), times.end());;
    long long mid = 0;
    long long sum = 0;
    
    while(left <= right) {
        
        mid = (left + right) / 2;
        sum = 0;
        for(int i=0; i<times.size(); i++){
            sum += mid / times[i]; 
        }
        
        if(sum >= n) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
}