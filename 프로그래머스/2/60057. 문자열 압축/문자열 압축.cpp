#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {

    if (s.length() == 1) return 1;
    

    int min_len = s.length(); 

    for (int i = 1; i <= s.length() / 2; i++) {
        string compressed = "";
        string prev = s.substr(0, i); 
        int count = 1;


        for (int j = i; j < s.length(); j += i) {
            string now = s.substr(j, i);
            
            if (prev == now) {
                count++; 
            } else {

                if (count > 1) {
                    compressed += to_string(count);
                }
                compressed += prev;
                
               
                prev = now;
                count = 1;
            }
        }

        if (count > 1) {
            compressed += to_string(count);
        }
        compressed += prev;

        min_len = min(min_len, (int)compressed.length());
    }

    return min_len;
}