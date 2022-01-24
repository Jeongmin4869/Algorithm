#include <string>
#include <vector>
#include <algorithm> // find

using namespace std;

int solution(vector<int> numbers) {
	int answer = 0;
	vector<int> allnum = { 1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < allnum.size(); i++) {
		if (find(numbers.begin(), numbers.end(), allnum[i]) == numbers.end())
			answer += allnum[i];
	}

	return answer;
}