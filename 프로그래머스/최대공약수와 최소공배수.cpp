#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int n, int m) {
	vector<int> answer;
	for (int i = min(n, m); i >= 1; i--) {
		if (n%i == 0 && m%i == 0) {
			answer.push_back(i);
			answer.push_back(n / answer[0] * m / answer[0] * answer[0]);
			break;
		}
	}

	return answer;
}