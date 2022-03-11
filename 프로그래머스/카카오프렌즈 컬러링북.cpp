#include <vector>
#include <string.h> // memset
using namespace std;

bool visit[100][100];
int num, cnt, N, M;
int dx[4];
int dy[4];

//깊이탐색
//DFS : 깊이우선탐색
//BFS : 너비우선탐색, 큐
void DFS(int x, int y, vector<vector<int>> picture, int num) {
	visit[x][y] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
		if (picture[nx][ny] == num && !visit[nx][ny]) {
			DFS(nx, ny, picture, picture[nx][ny]);
		}
	}
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0; // 구역
	int max_size_of_one_area = 0; // 가장 큰 구역 칸 개수
	memset(visit, false, sizeof(visit));
	num = 0, cnt = 0;
	N = n;
	M = m;
	dx[0] = 0, dx[1] = 0, dx[2] = 1, dx[3] = -1;
	dy[0] = 1, dy[1] = -1, dy[2] = 0, dy[3] = 0;


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && picture[i][j] != 0) {
				cnt = 0;
				DFS(i, j, picture, picture[i][j]);
				number_of_area++;
				if (cnt > max_size_of_one_area) max_size_of_one_area = cnt;
				cnt = 0;
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}