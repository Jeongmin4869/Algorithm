#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long solution(long long n) {
	long long answer = 0;
	vector<long long> num;
	string s = to_string(n);
	for (int i = 0; i < s.length(); i++) {
		num.push_back(s[i] - '0');
	}
	int size = num.size();
	sort(num.begin(), num.end(), greater<>());
	for (int i = 0; i < size; i++) {
		answer += num[i] * pow(10, size - 1 - i);
	}
	//스트링 정렬
	return answer;
}