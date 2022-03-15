#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

int count;
vector<int> friends[8];

//경우의 수 다 구하기??
int dfs(int n, vector<string> data) {
	for (int i = 0; i < data.size(); i++) {
		char A = data[0], B = data[2];

		switch (data[4]) {
		case '=':
			break;
		case '<':
			break;
		case '>':
			break;
		}

	}
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
	count = 0;
	friends = { A, C, F, J, M, N, R, T };
	//sstream


	int answer = 0; // 모든 조건을 만족하는 경우의 수
	return answer;
}