#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
//최대공약수 * (짧은면 / 짧은면)
long long solution(int w, int h) {
	long long answer = 1;
	int i = min(w, h);
	for (; i > 0; i--) {
		if (w%i == 0 && h%i == 0) break;
	}

	//짧은면의 
	cout << i;
	return answer = w * h - i;
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