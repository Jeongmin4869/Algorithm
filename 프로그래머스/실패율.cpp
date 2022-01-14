#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<int> stay;
	vector<float> fRate;
	int person = stages.size();

	stay.assign(N, 0);
	for (int i = 0; i < stages.size(); i++) {
		if (stages[i] <= N)
			stay[stages[i] - 1] ++;
	}

	for (int i = 0; i < stay.size(); i++) {
		if (person == 0) {
			fRate.push_back(0.0);
			continue;
		}
		fRate.push_back((float)stay[i] / person);
		person -= stay[i];
	}

	for (int i = 0; i < fRate.size(); i++) {
		int max_index = max_element(fRate.begin(), fRate.end()) - fRate.begin();
		answer.push_back(max_index + 1);
		fRate[max_index] = -1;
	}

	return answer;
}