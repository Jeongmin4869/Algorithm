#include <string>
#include <vector>
#include <set>
using namespace std;

string solution(string s) {
	string answer = "";
	multiset<char> set;
	for (auto i : s) set.insert(i);
	for (auto i = set.rbegin(); i != set.rend(); i++) answer += *i;
	return answer;
}