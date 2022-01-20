#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> //unique
#include <sstream> // istringstream

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	vector<int> ban;
	vector<string> data;
	unordered_map<string, int> hash;

	//중복값 제거
	sort(report.begin(), report.end());
	report.erase(unique(report.begin(), report.end()), report.end());

	for (int i = 0; i < report.size(); i++) {
		istringstream ss(report[i]);
	}

	//result : 각 이용자 당 받는 처리결과메일 갯수 ...  정지되면 0


	return answer;
}