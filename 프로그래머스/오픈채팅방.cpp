#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
	//map, vector
	unordered_map<string, string> map;
	vector<vector<string>> user;
	vector<string> answer;
	for (int i = 0; i < record.size(); i++) {
		vector<string> vec;
		stringstream stream1;
		stream1.str(record[i]);
		string id, state, name;
		stream1 >> state >> id >> name;

		if (state != "Change") {
			vec.push_back(state);
			vec.push_back(id);
			user.push_back(vec);
			cout << state << " ";
		}
		if (state != "Leave") map[id] = name;
	}
	cout << endl;
	for (auto a : user) {
		string s;
		s += map[a[1]] + "님이 ";
		a[0] == "Enter" ? s += "들어왔습니다." : s += "나갔습니다.";
		answer.push_back(s);
	}


	return answer;
}