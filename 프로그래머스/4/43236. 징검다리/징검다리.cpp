#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    
    vector<int> rrocks;
    for(auto i : rocks) rrocks.push_back(i);
    rrocks.push_back(distance);

    int del_rock = 0;
    int left = 1;
    int right = distance;
    int mid = 0;
    int ans = 0; // 바위 사이의 최소거리
    
    sort(rrocks.begin(), rrocks.end());    // 바위 간 거리 비교를 위한 정렬
    
    
    while(left <= right) {
        
        mid = (left + right) / 2;
        int prev = 0;
        del_rock = 0;
        for(auto i : rrocks) {
            int now_dist = i - prev;
            if(now_dist < mid) {
                del_rock++;
            }
            else{
                prev = i;
            }
        }
        if(del_rock <= n) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}

// 삭제한 돌의 개수 <= n -> 아직 돌을 더많이 삭제할 여유가 있다.

// 삭제 개수를 더 늘릴려면 -> 목표 최소 거리를 키워야 한다.
// 최소 거리를 늘리면 바위 사이의 거리를 더 많이 삭제할 수 있다.

// 왜냐면 문제의 요지는 바위 사이의 최소 거리를 최대로 하는 값을 구하는거다.