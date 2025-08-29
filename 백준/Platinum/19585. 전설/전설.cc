#include<iostream>
#include<queue>
#include<cstring>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include<utility>
#include<algorithm>
#include<iterator>
using namespace std;

struct TRIE;

//TRIE* nodes = new TRIE[4000 * 1000 + 1];

//static vector<TRIE> nodes(4000*1000+1);
static short prefixEnds[1001];
static int prefixIdx;

int newNodeIndex = 0;

struct TRIE {
	//unordered_map<char, TRIE*> 
	TRIE* Node[26];// = { 0, };// = { 0, };
	bool terminal;//=false;		// 단어 끝 표시
	/*
	TRIE() : terminal(false) 

		memset(Node, 0, sizeof(Node));
	}
	*/

	static TRIE* nodes;
	inline void insert(const char* str) {

		TRIE* p = this;
		while (*str) {

			int cur = *str - 'a';
			if (p->Node[cur] == NULL)
			{
				//nodes.emplace_back();
				p->Node[cur] = &nodes[newNodeIndex++];
			}
			p = p->Node[cur];
			str++;
		}
		p->terminal = true;		// 끝 표시
	}


	inline bool find(const char* str) 
	{
		prefixIdx = 0;
		memset(prefixEnds, -1, sizeof(prefixEnds));

		TRIE* p = this;
		int stringPos = 0;
		while (*str) {
			int cur = *str - 'a';
			if (p->Node[cur] == NULL) break;
			if (p->Node[cur]->terminal) prefixEnds[prefixIdx++] = stringPos;
			p = p->Node[cur];
			str++;
			stringPos++;
		}
		return prefixIdx>0;		// 끝 표시
	}
};
//vector<TRIE> TRIE::nodes(1);
TRIE* TRIE::nodes= (TRIE*)malloc(sizeof(TRIE)*(4000 * 1000 + 1));

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(TRIE::nodes, 0, sizeof(TRIE)*(4000 * 1000 + 1));

	TRIE* root = new TRIE();		// 트라이 생성


	unordered_set<string> nick_u_s;	// 닉네임 저장할 u_set
	int color_cnt = 0;				// 색깔의 수
	int nick_cnt = 0;				// 닉넴 수

	cin >> color_cnt >> nick_cnt;

	string color_str = "", nick_str = "";


	for (int i = 0; i < color_cnt; i++) {
		cin >> color_str;
		root->insert(color_str.c_str());
	}
	for (int i = 0; i < nick_cnt; i++) {
		cin >> nick_str;
		nick_u_s.insert(nick_str);
	}

	int q_cnt = 0;
	cin >> q_cnt;

	string now_str;

	for (int i = 0; i < q_cnt; i++) {

		cin >> now_str;

		// sub_str을 0부터 시작해서 다 구한다.

		int success = 0;
			if (root->find(now_str.c_str())) {		// 현재 접두사를 찾는다. true면

				//ex 3 

				for (int i = 0; i < prefixIdx; ++i)
				{
					string prefix = now_str.substr(prefixEnds[i] + 1);
					if (nick_u_s.find(prefix) != nick_u_s.end()) {
						cout << "Yes" << "\n";
						success = 1;
						break;
					}
				}
			}
	
		if (!success) cout << "No" << "\n";
	}

	return 0;
}