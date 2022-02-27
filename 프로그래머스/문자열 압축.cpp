#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = s.length();
	int len = 0, count = 1;
	string a, before;

	for (int i = 1; i <= s.length() / 2; i++) {
		len = 0;
		for (int j = 0; j < s.length(); j += i) {
			a = s.substr(j, i);
			len += a.length();
			if (before == a) {
				len -= a.length();
				count++;
			}
			else if (count > 1) {
				string count_s = to_string(count);
				len += count_s.length();
				count = 1;
			}
			before = a;
		}

		if (count > 1) {
			string count_s = to_string(count);
			len += count_s.length();
			count = 1;
		}
		if (answer > len) answer = len;
	}

	return answer;
}