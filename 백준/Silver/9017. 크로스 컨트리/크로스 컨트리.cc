#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void process() {
    int N;
    cin >> N;

    vector<int> runners(N);
    map<int, int> team_member_count;

    for (int i = 0; i < N; i++) {
        cin >> runners[i];
        team_member_count[runners[i]]++;
    }

    map<int, int> team_score;       
    map<int, int> team_passed_cnt; 
    map<int, int> team_fifth_score;

    int current_rank = 1; 

    for (int i = 0; i < N; i++) {
        int team = runners[i];

        if (team_member_count[team] == 6) {
            team_passed_cnt[team]++;

            if (team_passed_cnt[team] <= 4) {
                team_score[team] += current_rank;
            }
            if (team_passed_cnt[team] == 5) {
                team_fifth_score[team] = current_rank;
            }

            current_rank++; 
        }
    }

    // 3. 우승 팀 찾기
    int winner_team = -1;
    int min_score = 2147483647; // int max값 근사치

    for (auto i : team_member_count) {
        // 자격이 있는 팀만 비교
        if (i.second == 6) {
            int score = team_score[i.first];

            // 점수가 더 낮으면 갱신
            if (score < min_score) {
                min_score = score;
                winner_team = i.first;
            }

            else if (score == min_score) {
                if (team_fifth_score[i.first] < team_fifth_score[winner_team]) {
                    winner_team = i.first;
                }
            }
        }
    }

    cout << winner_team << "\n";
}

int main() {
    ios::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        process();
    }
    return 0;
}