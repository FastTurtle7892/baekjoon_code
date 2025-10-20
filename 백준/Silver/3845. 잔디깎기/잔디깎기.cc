#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;

// pair로
bool is_covered(vector<double>& arr, double w, double max_len) {

    vector<pair<double, double>> tmp;
    for (int i = 0; i < arr.size(); i++) {

        tmp.push_back({ arr[i] - w / 2.0, arr[i] + w / 2.0 });
    }
    sort(tmp.begin(), tmp.end());

    double start_len = tmp[0].second;

    for (int i = 1; i < tmp.size(); i++) {

        if (tmp[i].first > start_len) {
            return false;
        }
        else start_len = max(start_len, tmp[i].second);
    }
    if (start_len >= max_len) return true;
    else return false;
}


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string line;

    while (getline(cin, line) && line != "0 0 0.0") {

        stringstream ss(line);
        int nx, ny;
        double w;
        ss >> nx >> ny >> w;

        getline(cin, line);
        stringstream ss_x(line);
        vector<double> x_coords(nx);
        for (int i = 0; i < nx; ++i) {
            ss_x >> x_coords[i];
        }

        getline(cin, line);
        stringstream ss_y(line);
        vector<double> y_coords(ny);
        for (int i = 0; i < ny; ++i) {
            ss_y >> y_coords[i];
        }

        if (is_covered(x_coords, w, 75.0) && is_covered(y_coords, w, 100.0)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}