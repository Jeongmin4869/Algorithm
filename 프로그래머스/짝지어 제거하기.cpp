#include <iostream>
#include <string>
//#include <sstream>

using namespace std;

int solution(string s)
{
	int answer = 0;
	//stringstream str1;
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == s[i + 1]) {
			answer++;
			i = 0;
			//s변경
		}
	}
	return answer;
}