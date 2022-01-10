#include <string>
#include <vector>
#include<cstdlib> //abs for int, long int
#include <cmath>

using namespace std;

double cal(vector<int> po_1, vector<int> po_2)
{
	return sqrt(pow(po_1[0] - po_2[0], 2) +
		pow(po_1[1] - po_2[1], 2));
}


string solution(vector<int> numbers, string hand) {
	string answer = "";
	vector<int> lh = { 0,3 }; // x,y
	vector<int> rh = { 2,3 };
	vector<int> n_po = { 0,0 };
	char h = hand == "left" ? 'L' : 'R';

	for (int i = 0; i < numbers.size(); i++) {
		int num = numbers[i];

		if (num == 1 || num == 4 || num == 7) {
			answer += 'L';
			lh = { (num - 1) / 3, (num - 1) % 3 };

		}
		else if (num == 3 || num == 6 || num == 9) {
			answer += 'R';
			rh = { (num - 1) / 3, (num - 1) % 3 };
		}
		else { //2 5 8 0
			if (num == 0) n_po = { 1,3 };
			else n_po = { (num - 1) / 3, (num - 1) % 3 };

			if (cal(lh, n_po) < cal(rh, n_po)) {
				answer += 'L';
				lh = n_po;
			}
			else if (cal(lh, n_po) > cal(rh, n_po)) {
				answer += 'R';
				rh = n_po;
			}
			else {
				h == 'L' ? answer += 'L' : answer += 'R';
				h == 'L' ? lh = n_po : rh = n_po;
			}
		}
	}
	return answer;
}