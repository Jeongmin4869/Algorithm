#include <string>
#include <iostream>
using namespace std;

int solution(string s)
{
	int answer = 0, i = 0;
	while (i < s.length()) {
		if (s[i] == s[i + 1]) {
			s.erase(i, 2);
			i = 0;
		}
		else i++;
		if (s.length() == 0) return 1;
	}
	return 0;
}