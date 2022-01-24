#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
	int answer = 0;
	int num = 0;
	for (int i = 0; i < absolutes.size(); i++) {
		num = absolutes[i];
		if (signs[i]) answer += num;
		else answer -= num;
	}

	return answer;
}