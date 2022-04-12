#include <string>
#include <vector>

using namespace std;
int dx[4];
int dy[4];
int N, M; // xรเ, yรเ
void dfs(int x, int y, vector<string> place) {

	for (int i = 0; i < 4; i++) {
		x += dx[i];
		y += dy[i];
		if ((x > 0 && y > 0) && (x < N && y < M)) {
			//
		}
	}

}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	dx[0] = 1; dx[1] = 0; dx[2] = -1; dx[3] = 0;
	dy[0] = 0; dy[1] = 1; dy[2] = 0; dy[3] = -1;
	for (int i = 0; i < places.size(); i++) {
		N = places[i][0].size();
		M = places[i].size();
		//dfs
	}


	return answer;
}