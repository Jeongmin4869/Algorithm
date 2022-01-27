#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> sum(3, 0);

	vector<int> first = { 1,2,3,4,5 };
	vector<int> second = { 2,1,2,3,2,4,2,5 };
	vector<int> third = { 3,3,1,1,2,2,4,4,5,5 };

	for (int i = 0; i < answers.size(); i++) {
		//수포자 1
		if (answers[i] == first[i % 5]) sum[0] ++;
		//수포자 2
		if (answers[i] == second[i % 8]) sum[1]++;
		//수포자 3
		if (answers[i] == third[i % 10]) sum[2]++;
	}

	int max = *max_element(sum.begin(), sum.end());
	for (int i = 0; i < 3; i++) {
		if (sum[i] == max) answer.push_back(i + 1);
	}

	return answer;
}