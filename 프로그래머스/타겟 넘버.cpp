#include <string>
#include <vector>

using namespace std;
vector<int> datas;
int answer;
int tarN;
void dfs(int n, int before);

int solution(vector<int> numbers, int target) {
	answer = 0;
	datas = numbers;
	tarN = target;
	dfs(0, 0);

	return answer;
}

//dfs란 뭘까...
void dfs(int n, int before) {
	if (n == datas.size()) {
		if (before == tarN) answer++;
		return;
	}

	dfs(n + 1, before + datas[n]);
	dfs(n + 1, before - datas[n]);
	return;
}