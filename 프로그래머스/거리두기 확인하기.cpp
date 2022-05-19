#include <string>
#include <vector>
#include <string.h> // memset
#include <iostream>
using namespace std;
bool visited[100][100];

//1) O를 기준으로 상하좌우 P가 있는지 체크하자.(2개이상)
//2) P를 기준으로 상하좌우 P가 있는지 체크하자.(1개이상)

int dx[4];
int dy[4];
bool isSafe;
void dfs(int y, int x, vector<string> place, int count) {
	visited[y][x] = true;
	if (count > 2 || place[y][x] == 'X') {
		return;
	}
	else {
		if (count != 0 && place[y][x] == 'P') {
			isSafe = false;
			return;
		}

		for (int i = 0; i < 4; i++) {
			x += dx[i];
			y += dy[i];
			if ((x >= 0 && y >= 0) && (x < 5 && y < 5)) {
				if (!visited[y][x]) {
					dfs(x, y, place, count + 1);
				}
			}
		}
	}
	//return;
}

//P좌표로 풀기? 탐색으로 풀기?
vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	dx[0] = 1; dx[1] = 0; dx[2] = -1; dx[3] = 0;
	dy[0] = 0; dy[1] = 1; dy[2] = 0; dy[3] = -1;
	for (vector<string> place : places) {
		isSafe = true;
		memset(visited, false, sizeof(visited));
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				cout << place[y][x];
				if (place[y][x] == 'P') {
					//isSafe = true;
					dfs(y, x, place, 0);
					if (!isSafe) break;
				}
			}
			if (!isSafe) break;
		}
		isSafe == true ? answer.push_back(1) : answer.push_back(0);
		cout << endl;
	}
	return answer;
}