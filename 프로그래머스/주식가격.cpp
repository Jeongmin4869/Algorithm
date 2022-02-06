#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size(), 0);

	for (int i = 0; i < prices.size() - 1; i++) {
		//스텍에
		//오를때마다 +1하고...
		//낮아지면 pop?? <?>
	}
	//먼저 효율성을 통과하는 방법은 먼저 주어진 배열의 값에서 가장 큰 값의 값은 따로 처리 해주셔야 합니다 왜냐면 안그럼 말 그대로 전부다 구해야 하기 때문에 효율성이 매우 떨어지겠죠... for문 안에 while문을 사용하시는걸 추천합니다
	return answer;
}