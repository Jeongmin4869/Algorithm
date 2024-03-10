#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

// x^2 + y^2 = r^2

long long solution(int r1, int r2) {
    
    long long answer = (r2-r1+1)*4 ; // x 또는 y가 0일때 
    for(int i=1; i<r2; i++){
        
        long long max = floor(sqrt((long long)r2*r2 - (long long)i*i));
        long long small = floor(sqrt((long long)r1*r1 - (long long)i*i));
        answer += (max-small) * 4; // 작은 원이 격자점을 지나는 경우를 고려하지 않음
        if(i<r1 && sqrt((long long)r1*r1 - (long long)i*i) == small) answer += 4;

    }

    return answer;
}
