#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

/*
1. 각 기사는 자신의 기사 번호의 약수 개수에 해당하는 공격력을 가진 무기를 구매하려 한다.
2. 이웃나라와의 협약에 의해 공격력의 제한수치가 정해져있다.
3. 제한수치보다 큰 공격력을 가진 무기를 구매해야 하는 기사는 협약기관에서 정한 공격력을 가지는 무기를 구매해야한다.

- 기사단원의 수를 나타내는 정수 : number
- 이웃나라와 협약으로 정해진 공격력의 제한수치를 나타내는 정수 : limit
- 제한수치를 초과한 기사가 사용할 무기의 공격력을 나타내는 정수 : power
*/

int sosu(int num){
    int count = 0;
    for(int i=1; i<sqrt(num); i++){
        if(num%i == 0) count += 2;
    }
    
    if(pow((int)sqrt(num), 2) == num) count += 1;
    
    return count++;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i=1; i<= number; i++){
        int s = sosu(i);
        if(s > limit)
            answer += power;
        else 
            answer += s;
    }

    return answer;
}
