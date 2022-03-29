#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
vector<int> c;
vector<char> al;
vector<bool> visited;
//next_permutation?
// 3개로 구성된 유효한 코스가 {ABC}가 있다면 
// 4개로 구성된 코스는 {ABC + 'C 다음 알파벳'}의 경우로만 탐색해주면 됩니다
void dfs(string str, vector<string> &answer, vector<string> &orders) {
	int n = str.size();
	auto p = find(c.begin(), c.end(), n);
	if (p != c.end()) {
		bool b = true;
		for (int i = 0; i < orders.size(); i++) {
			for (int j = 0; j < str.size(); j++) {
				auto p2 = find(orders[i].begin(), orders[i].end(), str[j]);
				if (p2 == orders[i].end()) {
					b = false;
					break;
				}
			}

			if (b) answer.push_back(str);

		}
		//auto p = find(c.begin(), c.begin() + answer[i].size(),n);
		return;
	}

	//dfs 순열 구하기(중복허용X)
	for (int i = 0; i < al.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			string str2 = str + al[i];
			dfs(str2, answer, orders);
			visited[i] = false;
		}
	}
	return;

}
//dfs.. ????!!!
vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	set<char> s;
	c = course;

	for (int i = 0; i < orders.size(); i++) {
		for (int j = 0; j < orders[i].size(); j++) {
			s.insert(orders[i][j]);
		}
	}
	al.assign(s.begin(), s.end());

	visited.assign(al.size(), false);

	dfs("", answer, orders);

	return answer;
}