#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
	int answer = 0;

	if (sqrt(n) <= 1) {
		for (int i = 1; i <= n; i++) answer += i;
		return answer;
	}

	for (int i = 1; i <= sqrt(n); i++) {
		if (n%i == 0) {
			answer += i;
			answer += n / i;
		}
	}
	return answer;
}