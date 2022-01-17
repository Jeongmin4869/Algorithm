#include <string>
#include <cmath>
#include <vector>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int i = 0, j = 0;
	vector<int> num;
	char word;
	while (i + 2 < dartResult.length()) {
		num.push_back(dartResult[i] - '0');
		if (dartResult[i + 1] == '0') {
			printf("10존재 ");
			//num[j] = 10;
			//i++;
		}
		printf("%d ", num[j]);
		word = dartResult[i + 1];

		if (word == 'D') {
			num[j] = pow(num[j], 2);
		}
		else if (word == 'T') {
			num[j] = pow(num[j], 3);
		}

		word = dartResult.at(i + 2);
		if (word == '*') {
			num[j] = num[j] * 2;
			if (i != 0) {
				num[j - 1] = num[j - 1] * 2;
			}
		}
		else if (word == '#') {
			num[j] = num[j] * -1;
		}
		else {
			i += 2;
			j++;
			continue;
		}
		i += 3;
		j++;
	}


	printf("%d ", num[0]);
	printf("%d ", num[1]);
	printf("%d ", num[2]);

	return answer = num[0] + num[1] + num[2];
}