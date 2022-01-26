#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = s.length();
	int len = 0;
	int count = 0;
	string a, b_s, f_s;

	for (int i = 2; i < s.length() / 2; i++) {

		for (int j = 0; j < s.length(); j += i) {
			f_s = s.substr(j, i);
			//substr(3, 5)
			b_s = f_s;
		}

		if (a.length() < answer) answer = a.length();


	}

	return answer;
}