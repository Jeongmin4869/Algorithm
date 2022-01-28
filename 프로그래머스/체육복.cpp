#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = reserve.size();
	int num;
	for (int i = 0; i < reserve.size(); i++) {
		num = i + 1;
		auto it1 = find(lost.begin(), lost.end(), num - 1);
		auto it2 = find(lost.begin(), lost.end(), num + 1);
		if (it1 != lost.end()) {
			answer++;
			lost.erase(remove(lost.begin(), lost.end(), num - 1), lost.end());
		}
		else if (it2 != lost.end()) {
			answer++;
			lost.erase(remove(lost.begin(), lost.end(), num + 1), lost.end());
		}
	}


	return answer;
}