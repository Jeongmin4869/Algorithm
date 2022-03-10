#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	string answer = s;
	int count = 1;
	string a, before;
	string ex = "";

	for (int i = 1; i <= s.length() / 2; i++) {
		before = s.substr(0, i);
		for (int j = i; j < s.length(); j += i) {
			a = s.substr(j, i);
			if (before != a) {
				if (count > 1) ex += to_string(count);
				ex += before;
				count = 1;
			}
			else {
				count++;
			}
			before = a;
		}

		if (count > 1) ex += to_string(count);
		ex += before;
		count = 1;
		if (answer.size() > ex.size()) answer = ex;
		ex = "";
	}

	return answer.size();
}