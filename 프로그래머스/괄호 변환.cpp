#include <string>
#include <vector>
#include <stack>
using namespace std;

//괄호는 stack으로 해곃하고

string solution(string p) {
	string answer = "";
	stack<char> s;

	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') s.push('(');
		else {
			if (s.top() == '(') s.pop();
			else break;
		}
	}

	return answer = p;
}