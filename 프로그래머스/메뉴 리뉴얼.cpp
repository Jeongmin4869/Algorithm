#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
vector<int> c;
vector<char> al;
vector<bool> visited;
//N:3, M:2 // N은 원소의 개수, M은 뽑을 개수

//next_permutation?
// 3개로 구성된 유효한 코스가 {ABC}가 있다면 
// 4개로 구성된 코스는 {ABC + 'C 다음 알파벳'}의 경우로만 탐색해주면 됩니다

void dfs(string str, vector<string> &answer, vector<string> &orders) {
	int n = str.size();
	auto p = find(c.begin(), c.end(), str.size());
	if (p != c.end()) {

		bool b = true;
		int count = 0;
		for (int i = 0; i < orders.size(); i++) {
			count++;
			b = true;
			for (int j = 0; j < str.size(); j++) {
				auto p2 = orders[i].find(str[j]);
				if (p2 == string::npos) {
					b = false;
					break;
				}
			}
		}
		if (b && count > 1) answer.push_back(str);

		return;
	}

	//dfs 순열 구하기(순열은 중복만을 X할뿐 )
	// 순열로하면안된다 -> 조합
	// int i=str.size() 해주었음.. // 이럼안됨!
	for (int i = str.size(); i < al.size(); i++) {
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