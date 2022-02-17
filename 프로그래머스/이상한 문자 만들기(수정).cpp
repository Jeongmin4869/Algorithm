#include <string>
#include <vector>
#include <cstring>

using namespace std;

string solution(string s) {
	int n = 0;
	for (int i = 0; i < s.length(); i++, n++) {
		if (s[i] == ' ') {
			n = -1;
			continue;
		}
		n & 1 ? s[i] = tolower(s[i]) : s[i] = toupper(s[i]);
	}

	return s;
}