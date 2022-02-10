#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;
	multimap<char, string> hash;
	sort(strings.begin(), strings.end());
	for (int i = 0; i < strings.size(); i++) hash.insert(make_pair(strings[i][n], strings[i]));
	for (auto i : hash) answer.push_back(i.second);
	return answer;
}