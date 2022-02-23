#include <string>
#include <vector>
using namespace std;

string solution(string phone_number) {
	string answer = phone_number;
	answer.replace(answer.begin(), answer.end() - 4, answer.size() - 4, '*');
	return answer;
}