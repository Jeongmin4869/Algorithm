#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
bool check(string p);
//괄호는 stack으로 해곃하고

string solution(string p) {
	string answer = "";
	string u, v;
	stack<char> s;
	int count = 0;

	if (p.size() == 0) return "";

	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') {
			count++;
		}
		else if (p[i] == ')') {
			count--;
		}

		if (count == 0) {
			u = p.substr(0, i + 1); // 오류
			//v = p.substr(i+1, p.size()-i);
			cout << v;
			break;
		}
	}
	if (check(u)) {
		//solution(v);
	}
	//check(v);
	return p;//= u + v;
}

bool check(string p) {
	stack<int> s;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') {
			s.push(p[i]);
			//if (i < p.size() / 2) s.push(p[i]);
			//else p.replace(i - 1, 2, "()");
		}
		else if (p[i] == ')') {
			if (s.top() == '(') s.pop();
			//else { // '))'
			//	p.replace(i, 1, "(");
			//}
		}
	}

	return s.empty() ? true : false;
}
