#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> //unique, find
#include <sstream> // istringstream

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	string name;
	string report_name;
	int idx = 0;
	vector<vector<string>> user(id_list.size(), vector<string>()); // 계정당 신고한 id
	vector<int> report_count(id_list.size(), 0); //신고당한 횟수
	vector<int> answer(id_list.size(), 0);
	vector<string> report_user; // 정지된 유저 id

	//중복값 제거
	sort(report.begin(), report.end());
	report.erase(unique(report.begin(), report.end()), report.end());

	for (int i = 0; i < report.size(); i++) {
		istringstream ss(report[i]);
		ss >> name;
		idx = find(id_list.begin(), id_list.end(), name) - id_list.begin(); // index
		ss >> report_name;
		user[idx].push_back(report_name);
		idx = find(id_list.begin(), id_list.end(), report_name) - id_list.begin(); // index
		report_count[idx]++;
	}

	//정지된 아이디
	for (int i = 0; i < report_count.size(); i++) {
		if (report_count[i] >= k) {
			report_user.push_back(id_list[i]);
		}
	}

	for (int i = 0; i < user.size(); i++) {
		for (int j = 0; j < report_user.size(); j++) {
			if (find(user[i].begin(), user[i].end(), report_user[j]) != user[i].end())
				answer[i] = answer[i] + 1;
		}
	}

	return answer;
}