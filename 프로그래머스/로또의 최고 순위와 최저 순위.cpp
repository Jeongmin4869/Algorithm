#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer(2, lottos.size() + 1);
	//Á¤·Ä
	sort(lottos.begin(), lottos.end());
	sort(win_nums.begin(), win_nums.end());

	for (int i = 0; i < lottos.size(); i++) {
		if (lottos[i] == win_nums[i]) {
			answer[0] --;
			answer[1] --;
		}
		else if (win_nums[i] == 0) answer[0]--;
	}

	if (answer[1] == lottos.size() + 1) answer[1] = lottos.size();



	return answer;
}