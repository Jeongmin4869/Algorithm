#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> students(n, 1);

	for (int i = 0; i < lost.size(); i++) {
		students[lost[i]]--;
	}

	for (int i = 0; i < reserve.size(); i++) {
		students[reserve[i]]++;
	}

	for (int i = 0; i < n; i++) {
		if (students[i] == 0) {
			if (i > 0 && students[i - 1] > 1) { answer++; continue; }
			else if (i < n && students[i + 1] > 1) { students[i + 1]--; answer++; continue; }
		}
		else answer++;
	}

	return answer;
}