#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <cstdlib> // abs
#include <iostream>
using namespace std;

int answer;
vector<char> friends;
vector<bool> visited;
vector<string> datas;
void dfs(int n, string inputstr);
bool check(string str);

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
	answer = 0;
	friends = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
	visited.assign(8, false); // vector 초기화
	datas = data;
	dfs(0, "");

	return answer;
}


bool check(string str) {
	for (auto data : datas) {
		int idx1 = find(data.begin(), data.end(), data[0]) - data.begin();
		int idx2 = find(data.begin(), data.end(), data[2]) - data.begin();
		switch (data[3]) {
		case '=':
			if (abs(idx1 - idx2) != data[4] + 1) return false;
			break;
		case '<': // 미만
			if (abs(idx1 - idx2) >= data[4] + 1) return false;
			break;
		case '>': // 초과
			if (abs(idx1 - idx2) <= data[4] + 1) return false;
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
		string str = inputstr + friends[i];
		visited[i] = true;
		dfs(n + 1, str);
		visited[i] = false; // 숫자의 순서를 바꿔주기 위함 .. .
	}

	return;
}