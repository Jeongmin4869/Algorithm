#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	unordered_map<string, int> hash;
	for (int i = 0; i < id_list.size(); i++) {
		hash[id_list[i]];
	}
	for (int i = 0; i < report.size(); i++) {
		hash[report[i]] = hash[report[i]] + 1;
	}
	for (int i = 0; i < id_list.size(); i++) {
		answer.push_back(hash[id_list[i]]);
	}


	return answer;
}