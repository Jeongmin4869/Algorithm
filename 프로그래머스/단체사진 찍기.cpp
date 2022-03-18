#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <cstdlib> // abs
using namespace std;

int answer;
vector<char> names;
vector<bool> visited;
vector<string> conditions;
void dfs(int n, string inputstr);
bool check(string str);

int solution(int n, vector<string> data) {
	answer = 0;
	names = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
	visited.assign(8, false); // vector 초기화
	conditions = data;
	dfs(0, "");

	return answer;
}


bool check(string str) {
	for (auto c : conditions) {
		int idx1 = find(str.begin(), str.end(), c[0]) - str.begin();
		int idx2 = find(str.begin(), str.end(), c[2]) - str.begin();
		int len = abs(idx1 - idx2) - 1;
		int hope = c[4] - '0';
		switch (c[3]) {
		case '=':
			if (len != hope) return false;
			break;
		case '<': // 미만
			if (len >= hope) return false;
			break;
		case '>': // 초과
			if (len <= hope) return false;
			break;
		}
	}
	return true;
}

void dfs(int n, string inputstr) {
	if (n == 8) {
		if (check(inputstr)) answer++;
		return;
	}

	//경우의 수 다 구하기    
	for (int i = 0; i < visited.size(); i++) {
		if (!visited[i]) {
			string str = inputstr + names[i];
			visited[i] = true;
			dfs(n + 1, str);
			visited[i] = false; // 숫자의 순서를 바꿔주기 위함 .. . 
		}
	}

	return;
}