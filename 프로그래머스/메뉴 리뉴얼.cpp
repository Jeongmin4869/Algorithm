#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <map>

using namespace std;
vector<int> c;
vector<char> al;
vector<bool> visited;
map<string, int> hashMap;
//정답 봄

void dfs(int targetnum, string str, int n, vector<string> &answer, vector<string> &orders) {
	if (str.size() == targetnum)
		hashMap[str] += 1;
	return;
}

//dfs 순열 구하기(순열은 중복만을 X할뿐 )
// 순열로하면안된다 -> 조합
// int i=str.size() 해주었음.. // 이럼안됨!
for (int i = n; i < al.size(); i++) {
	if (!visited[i]) {
		visited[i] = true;
		string str2 = str + al[i];
		dfs(targetnum, str2, i, answer, orders); // visiited 없애기
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
	for (int i = 0; i < course.size(); i++) {
		dfs(course[i], "", 0, answer, orders);
		visited.assign(al.size(), false);
	}

	int max = 0;
	for (auto m : hashMap) {
		int n = m.second;
		if (n > max) max = n;
	}

	for (auto m : hashMap) {
		if (m.second == max) answer.push_back(m.first);
	}


	//sort(answer.begin(), answer.end());
	return answer;
}