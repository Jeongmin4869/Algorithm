using namespace std;

long long solution(int w, int h) {
	long long answer = 1;
	int all_sq = w * h;
	int m_sq = 0;
	//기울기를 w로 나눈다
	//h의 크기만큼 네모를 뺀다.

	answer = all_sq - m_sq;
	return answer;
}