#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> set_v(int a, int b) {
	vector < vector <int> > v;
	int n = 1;
	for (int i = 0; i < a; i++) {
		vector<int> ve;
		for (int j = 0; j < b; j++) {
			ve.push_back(n++);
		}
		v.push_back(ve);
	}
	return v;
}

//x1, y1, x2, y2
//세로가 X, 가로가 Y
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;
	vector<vector<int>> v = set_v(rows, columns);
	int min = 0;
	int temp, before, len, x, y, x1, x2, y1, y2;
	for (auto q : queries) {
		min = 100;
		x1 = q[0]; y1 = q[1];
		x2 = q[2]; y2 = q[3];
		len = (x2 - x1 + 1) * (y2 - y1 + 1) - (x2 - x1 - 1) * (y2 - y1 - 1);
		x = q[0] - 1; y = q[1] - 1;
		before = v[x][y++];
		min = before;
		for (int i = 0; i < len; i++) {
			temp = v[x][y];
			v[x][y] = before;
			before = temp;
			if (x == q[0] - 1) { // ->
				if (y + 1 > q[3] - 1) x++;
				else y++;
			}

			else if (y == q[3] - 1) { // 밑
				if (x + 1 > q[2] - 1) y--;
				else x++;
			}

			else if (x == q[2] - 1) { //<-
				if (y - 1 < q[1] - 1) x--;
				else y--;
			}

			else if (y == q[1] - 1) {// 위
				if (x - 1 > q[0] - 1) y++;
				else x--;
			}
			if (temp < min) min = temp;

		}
		if (temp < min) min = temp;
		answer.push_back(min);
		min = 100;
	}

	//이게 왜 돼..?? 진짜 킹받아.. -> 응안돼..
	return answer;
}