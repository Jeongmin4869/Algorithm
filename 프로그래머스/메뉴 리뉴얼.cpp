#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <map>

using namespace std;
vector<int> c;
vector<bool> visited;
map<string, int> hashMap;
//정답 봄

void dfs(int depth, string str, string order) {
	if (str.size() == targetnum) {
		hashMap[str] += 1;
	}

	// 순열로하면안된다 -> 조합
	for (int i = 0; i < order.size(); i++) {
		dfs(depth, order.substr(i + 1), str + order[i]);
	}
}
//dfs.. ????!!!
vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	set<char> s;
	c = course;

	for (string &order : orders)
		sort(order.begin(), order.end());

	visited.assign(al.size(), false);
	for (int i = 0; i < course.size(); i++) {
		dfs(course[i], "", 0);

		int sup = 0;
		for (auto m : hashMap) {
			sup = max(sup, m.second);
		}

		for (auto m : hashMap) {
			if (sup > 2 && m.second == sup)
				answer.push_back(m.first);
		}

		visited.assign(al.size(), false);
		hashMap.clear();
	}



	//sort(answer.begin(), answer.end());
	return answer;
}