#include <cmath>
#include <algorithm>

using namespace std;
//최소공배수
long long solution(int w, int h) {
	long long answer = 1;
	long long all_sq = w * h;
	long long m_sq = 0;
	long long hi = max(w, h); long long we = min(w, h);

	float a = sqrt(pow(we, 2) + pow(hi, 2));
	a /= we;
	float b = sqrt(pow(a, 2) - 1);
	m_sq = ceil(b) * we;// 반올림
	answer = all_sq - m_sq;
	return answer;
}