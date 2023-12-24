#include <string>
#include <vector>

using namespace std;

// 10c (c ≥ 0 인 정수) 형태인 정수들이 적힌 버튼
// 항상 최소한의 버튼을 눌러서 이동
// 0층으로 가기 위해 필요한 마법의 돌

int solution(int storey) {
    int answer = 0;
    
    while(storey>0){
        int n = storey%10;
        if(n>5 || (n == 5 && storey%100/10 >= 5)){
            answer += (10-n);
            storey += 10;
        }
        else{
            answer += n;
        }
        storey /= 10;
    }
    
    return answer;
}
