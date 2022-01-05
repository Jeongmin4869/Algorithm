#include <string>
#include <vector>


using namespace std;

string solution(string new_id) {
	string answer = "";
	//1�ܰ�
	for (int i = 0; i < new_id.length(); i++) {
		new_id[i] = tolower(new_id[i]);
	}
	//2�ܰ�
	for (int i = 0; i < new_id.length(); i++) {
		if ((new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') ||
			(new_id[i] >= 'a' && new_id[i] <= 'z') ||
			(new_id[i] >= '0' && new_id[i] <= '9')) {//����
			answer += new_id[i];
		}
	}
	//3�ܰ�
	for (int i = 0; i < answer.length() - 1; i++) {
		if (answer[i] == answer[i + 1] && answer[i] == '.') {
			answer.erase(i, 1);
			i--;
		}
	}
	//4�ܰ�
	if (answer[0] == '.') answer.erase(0, 1);
	if (answer[answer.length() - 1] == '.') answer.erase(answer.length() - 1, 1);
	//5�ܰ�
	if (answer == "") answer = "a";
	//6�ܰ�
	if (answer.length() >= 16) answer = answer.substr(0, 15);
	if (answer[answer.length() - 1] == '.') answer.erase(answer.length() - 1, 1);
	//7�ܰ�
	if (answer.length() <= 2) {
		char last = answer[answer.length() - 1];
		while (answer.length() < 3) {
			answer += last;
		}
	}

	return answer;
}