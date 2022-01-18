#include <string>
#include <cmath>
#include <vector>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int i = 0;
	vector<int> num(3, 0);
	char word;

	for (int j = 0; j < 3; j++) {
		num[j] = dartResult[i] - '0';
		if (dartResult[i + 1] == '0') {
			num[j] = 10;
			i++;
		}

		word = dartResult[++i];
		if (word == 'D') {
			num[j] = pow(num[j], 2);
		}
		else if (word == 'T') {
			num[j] = pow(num[j], 3);
		}

		if (dartResult[++i] != NULL) {
			word = dartResult[i];
			if (word == '*') {
				num[j] = num[j] * 2;
				if (i != 0) {
					num[j - 1] = num[j - 1] * 2;
				}
			}
			else if (word == '#') {
				num[j] = num[j] * -1;
			}
			else continue;
		}
		i++;
	}

	return answer = num[0] + num[1] + num[2];
}