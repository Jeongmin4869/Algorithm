#include <string>
#include <vector>
#include<cstdlib> //abs for int, long int
//#include <unordered_map>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int now_l = 0, now_r = 0;
	char h = hand == "left" ? 'L' : 'R';
	//unordered_map<int , int[]> hash;
	//hash[1] = [0,0];

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
		else { //2 5 8 0
			if (now_l + 2 == now_r) {// || now_l + 4 == now_r || now_l + 8 == now_r){
				answer += h;
				h == 'L' ? now_l = num : now_r = num;
			}
			else {
				//now_l + now_r == && 10 num == 5
				if (num == 8 && (now_l == 0 || now_r == 0)) {
					now_l == 0 ? answer += 'L' : answer += 'R';
					now_l == 0 ? now_l = num : now_r = num;
					printf("%s", answer.c_str());
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