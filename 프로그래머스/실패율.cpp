#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<int> p;
	vector<float> t;
	int person = stages.size();

	p.assign(N, 0);
	for (int i = 0; i < stages.size(); i++) {
		if (stages[i] <= N)
			p[stages[i] - 1] ++;
	}

	for (int i = 0; i < p.size(); i++) {
		t.push_back((float)p[i] / person);
		person -= p[i];
	}

	for (int i = 0; i < t.size(); i++) {
		int max_index = max_element(t.begin(), t.end()) - t.begin();
		printf("%d ", max_index);
		answer.push_back(max_index + 1);
		t[max_index] = -1;
	}


	return answer;
}