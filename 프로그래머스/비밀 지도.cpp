#include <string>
#include <vector>
#include <bitset>
using namespace std;

string to_binary(int num, int n) {
	string s = "";
	for (int i = 0; i < n; i++) {
		num % 2 == 0 ? s.insert(0, " ") : s.insert(0, "#");
		num >>= 1; // /=2
	}
	return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		answer.push_back(to_binary(arr1[i] | arr2[i], n));
	}
	return answer;
}