#include <vector>

using namespace std;

bool visit[100][100];
int num = 0, cnt = 0, N, M;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

//깊이탐색
//DFS : 깊이우선탐색
//BFS : 너비우선탐색, 큐
void DFS(int x, int y, vector<vector<int>> picture) {
	visit[x][y] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (picture[nx][ny] == 0 && !visit[nx][ny]) {
			DFS(nx, ny, picture);
		}
	}
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	visit[100][100] = { false, };
	num = 0, cnt = 0;
	//dx[4] = { 0, 0, 1, -1 };
	//dy[4] = { 1, -1, 0, 0 };
	N = n;
	M = m;


	//우측과 하단을 계속 스캔??



	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}