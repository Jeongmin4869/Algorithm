#include <string>
#include <vector>

using namespace std;


int solution(int n) {
	int answer = 0;
	vector<int> vec(n + 1, 0);
	vec[1] = 1;
	for (int i = 2; i <= n; i++) {
		vec[i] = vec[i - 1] % 1234567 + vec[i - 2] % 1234567;
	}
	return vec[n] % 1234567;
}