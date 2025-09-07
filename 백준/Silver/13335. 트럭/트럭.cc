#include <iostream>
#include <queue>

using namespace std;

int N, W, L;

queue<int> truck_vec;
queue<pair<int, int>> bridge;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> W >> L;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		truck_vec.push(input);
	}

	int pass_truck_cnt = 0;
	int now_time = 0;
	int now_inBridge_weight = 0;		// 현재 다리에 올라가있는 무게 총합
	while (pass_truck_cnt < N) {

		// 일단 트럭이 도착한지 안한지 확인한다. 트럭이 도착한 시간이면 트럭 무게 제외한다.

		if (!bridge.empty() && bridge.front().first == now_time) {
			now_inBridge_weight -= bridge.front().second;
			bridge.pop();
			pass_truck_cnt++;
		}

		// 다음 트럭이 올라갈 수 있다면 올린다. 트럭 종료 시간과 트럭의 무게를 pair로 큐에 넣는다. 
	
		if (!truck_vec.empty() && truck_vec.front() + now_inBridge_weight <= L) {
			
			now_inBridge_weight += truck_vec.front();
			bridge.push({ now_time + W, truck_vec.front() });
			truck_vec.pop();
		}
		now_time++;
	}
	cout << now_time << "\n";
	return 0;
}