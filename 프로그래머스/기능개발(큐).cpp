#include <string>
#include <vector>
#include <cmath>
#include <queue> 
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;
	for (int i = 0; i < progresses.size(); i++) {
		q.push(ceil((float)(100 - progresses[i]) / speeds[i]));
	}
	int count = 1, before = q.front(); q.pop();

	while (!q.empty()) {
		if (before >= q.front()) {
			count++;
		}
		else {
			answer.push_back(count);
			count = 1;
			before = q.front();
		}
		q.pop();
	}
	answer.push_back(count);

	return answer;
}