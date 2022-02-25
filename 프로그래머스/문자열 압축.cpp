#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = s.length();
	int len = 0;
	bool first = false;
	string a, before;

	for (int i = 2; i < s.length() / 2; i++) {
		for (int j = 0; j < s.length(); j += i) {
			a = s.substr(j, i);
			len += i;
			if (before == a) {
				len -= i;
				if (!first) len++, first = true;
			}
			else first = false;
		}
		if (answer > len) answer = len;
	}

	return answer;
}