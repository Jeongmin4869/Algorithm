#include <string>
#include <vector>
#include <string.h> // memset
using namespace std;
bool visited[100][100];
int dx[4];
int dy[4];
int N, M; // x축, y축  [y][x]
int dfs(int x, int y, vector<string> place, int count) {
	if (count > 2) return 1;

	for (int i = 0; i < 4; i++) {
		x += dx[i];
		y += dy[i];
		if ((x > 0 && y > 0) && (x < N && y < M)) {
			if (place[y][x] == 'X' && place[y][x] == 'O') {
				visited[y][x] = true;
				dfs(x, y, place, count++);
				visited[y][x] = false;
			}
		}
	}
	return 0;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	dx[0] = 1; dx[1] = 0; dx[2] = -1; dx[3] = 0;
	dy[0] = 0; dy[1] = 1; dy[2] = 0; dy[3] = -1;
	for (auto place : places) {
		memset(visited, false, sizeof(visited));
		N = place[0].size();
		M = place.size();
		int n = dfs(0, 0, place, 0);
		answer.push_back(n);
	}


	return answer;
}


/*
1) O를 기준으로 상하좌우 P가 있는지 체크하자.(2개이상)
2) P를 기준으로 상하좌우 P가 있는지 체크하자.(1개이상)
*/