#include <string>
#include <vector>
#include<cstdlib> //abs for int, long int

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int now_l = 0, now_r = 0;
	char h = hand == "left" ? 'L' : 'R';

	for (int i = 0; i < numbers.size(); i++) {
		int num = numbers[i];
		if (num == 1 || num == 4 || num == 7) {
			answer += 'L';
			now_l = num;
		}
		else if (num == 3 || num == 6 || num == 9) {
			answer += 'R';
			now_r = num;
		}
		else {
			if (now_l + 2 == now_r || now_l + 5 == now_r || now_l + 8 == now_r) {
				answer += h;
				h == 'L' ? now_l = num : now_r = num;
			}
			else {
				if (num == 8 && (now_l == 0 || now_r == 0)) {
					now_l == 0 ? answer += 'L' : answer += 'R';
					now_l == 0 ? now_l = num : now_r = num;
				}
				else if (abs(now_l - num) < abs(now_r - num)) {
					answer += 'L';
					now_l = num;
				}
				else {
					answer += 'R';
					now_r = num;
				}
			}
		}
	}
	return answer;
}