#include <string>
#include <vector>
#include <stack>
using namespace std;

//괄호는 stack으로 해곃하고

string solution(string p) {
	string answer = "";
	stack<char> s;

	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') {
			if (i < p.size() / 2) s.push(p[i]);
			else p.replace(i, 1, ")");
		}
		else { // ')'
			if (s.top() == '(') s.pop();
			else { // '))'
				p.replace(i, 1, "(");
			}
		}
	}

	return p;
}