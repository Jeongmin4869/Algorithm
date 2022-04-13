#include <string>
#include <vector>
#include <stack>
using namespace std;
bool check(string p);
//괄호는 stack으로 해결

string solution(string p) {
	string answer = "";
	string u, v;
	int count = 0;

	if (p.size() == 0) return "";

	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') {
			count += 1;
		}
		else if (p[i] == ')') {
			count -= 1;
		}

		if (count == 0) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1, p.size() - i);
			break;
		}
	}
	if (check(u)) {
		return u + solution(v);
	}
	u = u.substr(1, u.size() - 2);
	for (int i = 0; i < u.size(); i++) {
		if (u[i] == '(') u[i] = ')';
		else u[i] = '(';
	}
	return "(" + solution(v) + ")" + u;
}

bool check(string p) {
	stack<int> s;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') {
			s.push(p[i]);
		}
		else if (p[i] == ')') {
			if (s.empty()) return false;
			if (s.top() == '(') s.pop();
		}
	}

	return s.empty() ? true : false;
}