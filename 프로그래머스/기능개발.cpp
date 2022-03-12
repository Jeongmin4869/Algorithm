#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> days;

	for (int i = 0; i < progresses.size(); i++) {
		days.push_back(ceil((float)(100 - progresses[i]) / speeds[i]));
	}
	int count = 1, before = days[0];

	for (int i = 1; i < days.size(); i++) {
		if (before >= days[i]) {
			count++;
		}
		else {
			answer.push_back(count);
			count = 1;
			before = days[i];
		}
	}
	answer.push_back(count); // 얘의 이유

	return answer;
}