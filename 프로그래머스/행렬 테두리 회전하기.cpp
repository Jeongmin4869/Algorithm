#include <string>
#include <vector>

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
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;
	vector<vector<int>> v = set_v(rows, columns);
	int min = 0;
	int temp, len, x, y;
	for (auto q : queries) {
		min = 0;
		len = (x2 - x1) * (y2 - y1) - (x2 - x1 - 2) * (y2 - y1 - 2);
		x = q[0]; y = q[1];
		temp = v[y][x++];
		for (int i = 0; i < len; i++) {
			v[y][x] = temp;
			if (y == q[i]) { // ->
				if (x + 1 > q[2]) y++;
				else x++;
			}

			else if (x == q[2]) { // 밑

			}

			else if (y == q[3]) {
				< -


			}

			else if (x == q[0]) {
				위


			}
			temp = v[y][x];

		}
		answer.push_back(min);
	}


	return answer;
}