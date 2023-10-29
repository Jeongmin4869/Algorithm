/* 아래 코드는 런타임 에러가 발생하는데 이유를 찾을 수 없음... */

/*
#include <string>
#include <vector>

using namespace std;



출처 : 프로그래머스

이문제는 재귀함수로 풀 수 있는데 3가지 경우를 생각해야한다.

1. N 을 더하는경우
2. 2를 곱하는경우
3. 3을 곱하는경우
다만 이렇게만 구현하면 이미 계산된 x 값에 대한 count가 중복 계산되어지는 "비둘기집의 원리" 현상이 발생한다.

따라서 x 값에 대한 최소 count 를 기록하기위해 countArr 를 이용하여 메모이제이션 기법을 사용한다.
현재 count 값이 기록된 x 값에대한 count 값보다 클경우 MAX 값을 리턴하여 이미 이루어진 연산이 다시 수행되는것을 막는다.



int MIN = 1000001;
int countArr[1000001] = { 0, }; // 메모이제이션 

int convert(int count, int x, int y, int n){
    
    if( countArr[x] != 0 && countArr[x] <= count ) return countArr[x];
    
    countArr[x] = count;
   
    if(x == y) {
        return count;
    }
    
    int plus = MIN;
    int mul2 = MIN;
    int mul3 = MIN;
    
    if(x-n >= y){
        plus = convert(count+1,x-n, y, n);
    }
    
    if(x%2 == 0 && x/2 >= y){
        mul2 = convert(count+1,x/2, y, n);
    }
    
    if(x%3 == 0 && x/3 >= y){
        mul3 = convert(count+1,x/3, y, n);
    }
    
    return min(plus, min(mul2, mul3));
    
}

int solution(int x, int y, int n) {
    int answer = 0;
    
    answer = convert(0, y, x, n);
    
    if(answer >= MIN) return -1;
    
    return answer;
}


*/


#include <string>
#include <vector>

using namespace std;

int MIN = 1000001;
int countArr[1000001] = { 0, }; // 메모이제이션 

int convert(int count, int x, int y, int n){
    
    if( countArr[x] != 0 && countArr[x] <= count ) return MIN;
    
    countArr[x] = count;
   
    if(x == y) {
        return count;
    }
    
    int plus = MIN;
    int mul2 = MIN;
    int mul3 = MIN;
    
    if(x+n <= y){
        plus = convert(count+1,x+n, y, n);
    }
    
    if( x*2 <= y){
        mul2 = convert(count+1,x*2, y, n);
    }
    
    if(x*3 <= y){
        mul3 = convert(count+1,x*3, y, n);
    }
    
    return min(plus, min(mul2, mul3));
    
}

int solution(int x, int y, int n) {
    int answer = 0;
    
    answer = convert(0, x, y, n);
    
    if(answer >= MIN) return -1;
    
    return answer;
}
