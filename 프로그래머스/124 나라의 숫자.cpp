#include <string>
#include <vector>
using namespace std;

string solution(int n) {
	//3진법
	string answer = "";
	vector<string> nara = { "1","2","4" };
	while (n > 0) {
		n = n - 1;
		answer.insert(0, nara[n % 3]);
		n = n / 3;
	}
	return answer;
}