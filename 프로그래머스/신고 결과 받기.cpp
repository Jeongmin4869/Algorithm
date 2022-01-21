#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> //unique
#include <sstream> // istringstream

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	string name;
	string report_name;
	int idx = 0;
	vector<vector<string>> user(id_list.size(), vector<string>());
	vector<int> report_count(id_list.size(), 0); //신고당한 횟수
	vector<int> answer(id_list.size(), 0);
	vector<string> report_user;
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
		report_count[i]++;
	}

	for (int i = 0; i < report_count.size(); i++) {
		if (report_count[i] >= k) {
			//정지된 아이디
			report_user.push_back(id_list[i]);
		}
	}

	return answer;
}