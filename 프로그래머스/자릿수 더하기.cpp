#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
	string s = to_string(n);
	int answer = 0;
	for (int i = 0; i < s.length(); i++) {
		answer += s[i] % '0';
	}
	return answer;
}