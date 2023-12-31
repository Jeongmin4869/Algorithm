#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 가장 큰 양의 정수 a
// 철수가 가진 카드들에 적힌 모든 숫자를 나눌 수 있고 영희가 가진 카드들에 적힌 모든 숫자들 중 하나도 나눌 수 없는 양의 정수 a
// 영희가 가진 카드들에 적힌 모든 숫자를 나눌 수 있고, 철수가 가진 카드들에 적힌 모든 숫자들 중 하나도 나눌 수 없는 양의 정수 a

int gcd(int a, int b){
    if(a%b==0) return b;
    return gcd(b, a%b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int num1 = arrayA[0], num2 = arrayB[0];
    for(int i=0; i<arrayA.size(); i++){
        num1 = gcd(max(num1, arrayA[i]), min(num1, arrayA[i]));
    }
    
    for(int i=0; i<arrayB.size(); i++){
        num2 = gcd(max(num2, arrayB[i]), min(num2, arrayB[i]));
    }
    
    int answer1 = num2;
    for(int i=0; i<arrayA.size(); i++){
        if(arrayA[i]%num2 == 0) {
            answer1 = 0;
            break;
        }
    }
    
    int answer2 = num1;
    for(int i=0; i<arrayB.size(); i++){
        if(arrayB[i]%num1 == 0) {
            answer2 = 0;
            break;
        }
    }
    
    return max(answer1, answer2);
    
    // 이게 왜 통...과..
}
