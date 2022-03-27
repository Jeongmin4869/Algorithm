#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> c;
vector<char> al;
//dfs.. ????!!!
vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	c = course;

	for (int i = 0; i < orders.size(); i++) {
		for (int j = 0; j < orders[i].size(); j++) {
			auto p = find(al.begin(), al.end(), orders[i][j]);
			if (p != al.end()) al.push_back(orders[i][j]);
		}
	}

	sort(orders.begin(), orders.end());

	return answer;
}


void dfs(string s, vector<string> answer) {
	auto p = find(c.begin(), c.end(), s.size());
	if (p != c.end()) {
		answer.push_back(s);
		return;
	}


	return;

}