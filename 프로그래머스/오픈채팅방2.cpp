#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
	unordered_map<string, string> map;
	vector<string> answer;
	string id, state, name;
	for (int i = 0; i < record.size(); i++) {
		stringstream stream1;
		stream1.str(record[i]);
		stream1 >> state >> id >> name;
		if (state != "Leave") map[id] = name;
	}
	for (auto a : record) {
		string s = "";
		stringstream stream1;
		stream1.str(a);
		stream1 >> state >> id;
		if (state == "Change")
			continue;
		s += map[id] + "님이 ";
		state == "Enter" ? s += "들어왔습니다." : s += "나갔습니다.";
		answer.push_back(s);
	}


	return answer;
}