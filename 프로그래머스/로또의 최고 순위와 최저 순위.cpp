#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer(2, lottos.size() + 1);

	for (int i = 0; i < 6; i++) {
		int num = lottos[i];
		if (find(win_nums.begin(), win_nums.end(), num) != win_nums.end()) {
			answer[0] --;
			answer[1] --;
		}
		else if (num == 0) answer[0] --;
	}

	if (answer[0] >= 6) answer[0] = 6;
	if (answer[1] >= 6) answer[1] = 6;

	return answer;
}