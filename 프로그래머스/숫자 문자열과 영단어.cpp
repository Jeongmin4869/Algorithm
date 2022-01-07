#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = 0;
	string arr[] = { "zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	while (i < len) {
		if (s.find(arr[i]) != string::npos)
			s = s.replace(s.find(arr[i]), arr[i].length(), to_string(i));
		else i++;
	}

	return stoi(s);
}