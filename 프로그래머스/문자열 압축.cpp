#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = s.length();
	int len = 0;
	string a, b_s, f_s;

	for (int i = 2; i < s.length() / 2; i++) {
		a = s;
		if (a.length() < answer) answer = a.length();
	}

	return answer;
}