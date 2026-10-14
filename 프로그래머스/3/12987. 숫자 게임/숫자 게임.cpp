#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    
    int cnt = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int b_index = 0;
    for(int i=0; i<A.size(); i++) {
        while(b_index < B.size() && B[b_index] <= A[i] ){
            
            b_index++;
        }
        if(b_index == B.size()) break;
        b_index++;
        cnt++;
    }
    return cnt;
}

// 5 1 3 7

// 크기가 작은 순서대로 오름 차순으로 정렬
// 1 3 5 7

// b 팀은 이에 맞춰서 오름 차순으로 정렬

// 2 2 6 8