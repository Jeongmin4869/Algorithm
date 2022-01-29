#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size();
	int j, k = 0;
	for (int i = 0; i < lost.size(); i++) {
		for (j = k; j < reserve.size(); j++) {
			if ((lost[i] == reserve[j]) ||
				(lost[i] - 1 == reserve[j]) ||
				(lost[i] + 1 == reserve[j])) {
				k = j + 1;
				answer++;
				break;
			}
		}
	}

	return answer;
}