#include <string>
#include <iostream>
#include <cstring>
using namespace std;

bool solution(string s)
{
	int answer = 0;
	for (int i = 0; i < s.size(); i++) {
		if (tolower(s[i]) == 'p') answer++;
		else if (tolower(s[i]) == 'y') answer--;
	}
	return answer != 0 ? false : true;
}