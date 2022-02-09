#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b) {
	long long answer = 0;
	int n = min(a, b);
	int x = max(a, b);
	while (n <= x) {
		answer += n++;
	}
	return answer;
}