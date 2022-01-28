#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size();
	int j = 0;
	for (int i = 0; i < lost.size(); i++) {
		if ((lost[i] == reserve[j]) ||
			(lost[i] - 1 == reserve[j]) ||
			(lost[i] + 1 == reserve[j])) j++, answer++;

		if (j == reserve.size()) break;
	}

	return answer;
}