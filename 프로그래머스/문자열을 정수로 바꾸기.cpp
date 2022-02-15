#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = 1;
	if (s[0] == '-') {
		answer = -1;
		s = s.substr(1, s.length() - 1);
	}
	answer *= stoi(s);
	//answer = stoi(s)만 해주어도 된다. 부호도 저절로 바꿔준다.
	return answer;
}