#include <string>
#include <vector>
#include <iostream>
using namespace std;




vector<vector<int>> solution(int n, bool clock) {
	vector<vector<int>> answer(n, vector <int>(n, 0));
	vector<vector<int>> po = { {0,0}, {0,n - 1},{n - 1,n - 1},{n - 1,0} }; // y, x
	int dx[4], dy[4];
	if (clock) {
		dx[0] = { 1 }; dx[0] = { 0 }; dx[2] = { -1 }; dx[3] = { 0 };
		dy[0] = { 0 }; dy[1] = { 1 }; dy[2] = { 0 }; dy[3] = { -1 };
	}
	else {
		dx[0] = { 0 }; dx[1] = { -1 }; dx[2] = { 0 }; dx[3] = { 1 };
		dy[0] = { 1 }; dy[1] = { 0 }; dy[2] = { -1 }; dy[3] = { 0 };
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			answer[po[j][0]][po[j][1]] = i + 1;
			for (int k = 0; k < 4; k++) {
				int nx = po[j][1] + dx[(k + j) % 4];
				int ny = po[j][0] + dy[(k + j) % 4];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n || answer[ny][nx] != 0) continue;
				else {
					po[j][1] = nx;
					po[j][0] = ny;
					cout << j << " : " << nx << "," << ny << endl;
					break;
				}
			}
		}
		cout << endl;
	}

	return answer;
}