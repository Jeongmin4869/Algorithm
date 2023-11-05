#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long num : numbers){
        // 짝수의 경우 맨 마지막 숫자가 무조건 0이기 때문에 바로 다음수를 insert
        if(num%2==0){
            answer.push_back(num+1);
            continue;
        }
        
        long long n = num+1;
        
        while(1){
            long long temp = num^n; // XOR 연산
            int count = 0;
            while(temp > 0){
                if(temp%2==1){
                    count ++;
                    if(count > 2) break;
                }
                temp /=2;
            }
            if(count <= 2){
                answer.push_back(n);
                break;
            }
            n +=1 ;
        }
    }
    
    
    long long bit = 1;
            // 가장 오른쪽부터 차례로 n 개의 연속된 1 로 이루어진 비트구하기
            while (true) {
                if ((numbers[i] & bit) == 0) break;
                bit *= 2; // 곱하기 2 를 하면 다음 비트로
            }
            bit = bit / 2;

            // 구한 비트 더해주기
            answer.push_back(numbers[i] + bit);
    
    
    return answer;
}
