#include <string>
#include <cmath>
#include <vector>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int i = 0;
	vector<int> score(3, 0);
	char word;

	for (int j = 0; j < 3; j++) {
		score[j] = dartResult[i] - '0';
		if (dartResult[i + 1] == '0') {
			score[j] = 10;
			i++;
		}

		word = dartResult[++i];
		if (word == 'D') {
			score[j] = pow(score[j], 2);
		}
		else if (word == 'T') {
			score[j] = pow(score[j], 3);
		}

		if (dartResult[++i] != NULL) {
			word = dartResult[i];
			if (word == '*') {
				score[j] = score[j] * 2;
				if (i != 0) {
					score[j - 1] = score[j - 1] * 2;
				}
			}
			else if (word == '#') {
				score[j] = score[j] * -1;
			}
			else continue;
		}
		i++;
	}

	return answer = score[0] + score[1] + score[2];
}