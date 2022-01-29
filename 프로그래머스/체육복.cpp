#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> students(n, 1);

	for (int i : lost) students[i - 1]--;
	for (int i : reserve) students[i - 1]++;

	for (int i = 0; i < n; i++) {
		if (students[i] == 0) {
			if (i > 0 && students[i - 1] > 1) { answer++; continue; }
			if (i < n - 1 && students[i + 1] > 1) { students[i + 1]--; answer++; continue; }
		}
		else answer++;
	}

	return answer;
}