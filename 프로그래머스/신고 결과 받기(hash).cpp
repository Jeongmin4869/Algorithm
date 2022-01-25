#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> //unique, find
#include <sstream> // istringstream
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	string name;
	string name2;
	vector<int> answer(id_list.size(), 0);

	unordered_map<string, set<string>> um; // 신고한사람, 신고당한사람 // set
	unordered_map<string, int> um2; // 신고당한사람, 신고당한횟수

	//중복값 제거
	sort(report.begin(), report.end());
	report.erase(unique(report.begin(), report.end()), report.end());

	for (int i = 0; i < report.size(); i++) {
		istringstream ss(report[i]);
		ss >> name;
		ss >> name2;
		um[name].insert(name2);
		um2[name2]++;
	}

	for (int i = 0; i < id_list.size(); i++) {
		name = id_list[i];
		for (auto j : um[name]) {
			if (um2[j] >= k) answer[i] += 1;
		}
	}

	return answer;
}