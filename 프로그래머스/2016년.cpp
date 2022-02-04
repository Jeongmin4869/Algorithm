#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
	vector<int> month = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	vector<string> week = { "THU","FRI","SAT","SUN","MON","TUE","WED" };

	int num = b;
	for (int i = 0; i < a - 1; i++) num += month[i];

	return week[num % 7];
}