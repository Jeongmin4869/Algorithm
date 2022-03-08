#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int w, int h) {
	long long answer = 1;
	long long a = min(w, h);// 최대공약수 (모서리 모서리로 이어지는 네모의 개수)
	for (; a > 0; a--) {
		if (w%a == 0 && h%a == 0) break;
	}
	cout << a;
	return answer = w * h - (a - 1) * (a - 2);
}

/*

짱 망해버린 코드 나중에 왜 정답이 안나온건지 리뷰할것임!
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
*/