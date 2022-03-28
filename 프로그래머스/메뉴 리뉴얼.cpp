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
void dfs(string str, vector<string> &answer) {
	int n = str.size();
	auto p = find(c.begin(), c.end(), n);
	if (p != c.end()) {
		cout << ",";
		answer.push_back(str);
		return;
	}

	//dfs 순열 구하기(중복허용X)
	for (int i = 0; i < al.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			string str2 = str + al[i];
			dfs(str2, answer);
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

	dfs("", answer);

	return answer;
}