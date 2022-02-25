#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = s.length();
	int len = 0;
	bool first = false;
	string a, before;

	for (int i = 1; i <= s.length() / 2; i++) {
		len = 0;
		for (int j = 0; j < s.length(); j += i) {
			a = s.substr(j, i);
			len += i;
			if (before == a) {
				printf("%d ", i);
				len -= i;
				if (!first) len++, first = true;
			}
			else first = false;
			before = a;
		}
		if (answer > len) answer = len;
	}

	return answer;
}