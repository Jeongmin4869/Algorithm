#include <vector>

using namespace std;

//깊이탐색...
void DFS(int x, int y) {
	visit[x][y] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (arr[nx][ny] == 0 && !visit[nx][ny]) {
			DFS(nx, ny);
		}
	}
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	//우측과 하단을 계속 스캔??



	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}