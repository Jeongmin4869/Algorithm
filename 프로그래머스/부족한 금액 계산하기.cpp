using namespace std;

long long solution(int price, int money, int count)
{
	long answer = 0;
	for (int i = count; i > 0; i--) {
		answer += (long)(price * i);
	}
	return answer - money > 0 ? answer - money : 0;
}