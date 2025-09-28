#include <iostream>
#include <queue>

using namespace std;


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    vector<int> y(N + 2, 0);
    vector<int> n(N + 2, 0);

    y[1] = 1;

    int tp, start, end;
    for(int i=2; i<= N+1; i++){
        cin >> tp >> start >> end;

        if (tp == 1) {
            if (y[end] - y[start - 1] == end - start + 1) {
                
                y[i] = y[i - 1] + 1;
                n[i] = n[i - 1];
                cout << "Yes\n";
            }
            else {
                n[i] = n[i - 1] + 1;
                y[i] = y[i - 1];
                cout << "No\n";
            }
        }

        else {
            if (n[end] - n[start - 1] == end - start + 1) {

                y[i] = y[i - 1] + 1;
                n[i] = n[i - 1];
                cout << "Yes\n";
            }
            else {
                n[i] = n[i - 1] + 1;
                y[i] = y[i - 1];
                cout << "No\n";
            }
        }

    }

    return 0;
}