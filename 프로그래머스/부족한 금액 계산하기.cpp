using namespace std;

long long solution(int price, int money, int count)
{
	long long answer = 0;
	for (int i = count; i > 0; i--) {
		answer += (price * i);
	}
	return answer - money > 0 ? answer - money : 0;
}