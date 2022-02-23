#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
	string s = to_string(x);
	int num = 0;
	for (int i = 0; i < s.length(); i++) num += s[i] - '0';
	return x % num == 0;
}