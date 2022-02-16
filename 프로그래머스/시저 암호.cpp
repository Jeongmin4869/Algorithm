#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string s, int n) {
	string answer = "";
	for (auto &a : s) {
		if (islower(a)) {
			a += n % 26;
			if (!islower(a))
				a -= 26;
		}
		else if (isupper(a)) {
			a += n % 26;
			if (!isupper(a))
				a -= 26;
		}
	}
	return s;
}