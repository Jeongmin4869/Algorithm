#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <map>

using namespace std;
map<string, int> hashMap;
//정답 봄

void dfs(int targetnum, string str, string order) {
	if (str.size() == targetnum) {
		hashMap[str] += 1;
		return;
	}

	//dfs 순열 구하기(순열은 중복만을 X할뿐 )
	// 순열로하면안된다 -> 조합
	// int i=str.size() 해주었음.. // 이럼안됨!
	for (int i = 0; i < order.size(); i++)
		dfs(targetnum, str + order[i], order.substr(i + 1));
	return;
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	//없으면 오류
	for (string &order : orders)
		sort(order.begin(), order.end());


	for (int cur : course) {
		for (string order : orders)
			dfs(cur, "", order);

		int sup = 0;
		for (auto m : hashMap)
			sup = max(sup, m.second);

		for (auto m : hashMap)
			if (sup >= 2 && m.second == sup)
				answer.push_back(m.first);

		hashMap.clear();
	}


	sort(answer.begin(), answer.end());
	return answer;
}