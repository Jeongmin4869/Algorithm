#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> num;

	while (n > 0) {
		num.push_back(n % 3);
		n /= 3;
	}

	for (int i = 0; i < num.size(); i++) {
		answer += num[i] * pow(3, num.size() - i - 1);
	}


	return answer;
}