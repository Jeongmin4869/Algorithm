#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

//괄호는 stack으로 해곃하고

string solution(string p) {
	string answer = "";
	string u, v;
	stack<char> s;
	int count = 0;
	int i;
	for (i = 0; i < p.size(); i++) {
		if (p[i] == '(') {
			count++;
		}
		else if (p[i] == ')') {
			count--;
		}

		if (count == 0) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1, p.size() - i);
			cout << v;
			break;
		}
	}

	return p;
}

/*
만일 반복문으로 전체 문자열 w를 순차적으로 접근하였다면 당연히 언젠가는 '(' 의 개수와 ')' 의 개수가 처음으로 일치하는 상황이 나오는데 이때 처음으로 전체 문자열 w가 균형잡힌 문자열 u, v로 분리가 일어나고 v 문자열을 재귀 함수로 보내는 겁니다 또한 이와 동시에 u 문자열은 올바른 괄호 문자열인지 아닌지에 따라서 3번 루트를 탈지 4번 루트를 탈지 결정 되는 겁니다.

1번. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.

2번. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.

3번. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.

3-1번. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.

4번. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.

for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(') {
			if (i < p.size() / 2) s.push(p[i]);
			else p.replace(i - 1, 2, "()");
		}
		else { // p[i] ==')'
			if (s.top() == '(') s.pop();
			else { // '))'
				p.replace(i, 1, "(");
			}
		}
	}

*/