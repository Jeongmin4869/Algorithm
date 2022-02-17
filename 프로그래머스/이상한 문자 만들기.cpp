#include <string>
#include <vector>
#include <cstring>

using namespace std;

string solution(string s) {
	int n = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			n = 0;
			continue;
		}

		if (n) {
			s[i] = tolower(s[i]);
			n--;
		}
		else {
			s[i] = toupper(s[i]);
			n++;
		}
	}

	return s;
}