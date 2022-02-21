#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int n, int m) {
	vector<int> answer;
	int num = 2;
	for (int i = min(n, m); i >= 1; i--) {
		if (n%i == 0 && m%i == 0) {
			answer.push_back(i);
			break;
		}
	}

	for (int i = min(n, m); i <= n * m; i = min(n, m) * num++) {
		if (i%max(n, m) == 0) {
			answer.push_back(i);
			break;
		}
	}
	return answer;
}