#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	stringstream stream1;
	for (int i = 1; i < record.size(); i++) {
		stream1.str(record[i]);
		string id, state, s;
		stream1 >> state >> id;
		stream1 >> id;
		s += id + "���� ";
		state == "Enter" ? s += "���Խ��ϴ�." : s += "�������ϴ�.";
		answer.push_back(s);
	}
	return answer;
}