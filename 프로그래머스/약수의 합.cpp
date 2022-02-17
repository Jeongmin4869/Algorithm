#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
	int answer = 0;

	if (pow((int)sqrt(n), 2) == n) answer += (int)sqrt(n);

	for (int i = 1; i < sqrt(n); i++) {
		if (n%i == 0) {
			answer += i;
			answer += n / i;
		}
	}
	return answer;
}