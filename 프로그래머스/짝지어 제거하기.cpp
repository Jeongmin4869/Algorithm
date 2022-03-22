#include <string>
#include <iostream>
#include <stack> 
using namespace std;

//while문은 효율성 테스트 통과 X
//O(n)으로 통과해야 ..
int solution(string s)
{
	stack<int> st;
	for (int i = 0; i < s.length(); i++) {
		if (!st.empty() && st.top() == s[i]) {
			st.pop();
		}
		else st.push(s[i]);
	}
	return st.empty() ? 1 : 0;
}