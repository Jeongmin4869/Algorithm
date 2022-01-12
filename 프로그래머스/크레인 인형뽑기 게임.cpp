#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int count = 0;
	vector<int> box = {};
	int num = 10;

	for (int i = 0; i < moves.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[j][moves[i] - 1] != 0) {
				num = moves[i] - 1;
				if (!box.empty() && box.back() == board[j][num]) {
					box.pop_back();
					count += 2;
				}
				else box.push_back(board[j][num]);
				board[j][num] = 0;
				break;
			}
		}
	}
	return count; // 사라진 인형의 갯수
}