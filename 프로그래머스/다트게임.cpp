#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int i = 0;
	while (i + 2 < dartResult.length()) {
		int num = dartResult.at(i) - '0';
		char char1 = dartResult.at(i + 1);
		if (char1 == 'S') {
			answer += num;
		}
		else if (char1 == 'D') {
			answer += pow(num, 2);
		}
		else answer += pow(num, 3);

		char char2 = dartResult.at(i + 2);

		if (char2 >= '0' &&char2 <= '9') {
			i += 2;
			continue;
		}
		else {
			//if(char2 == '*')
		}
		i += 3;
	}
	return answer;
}