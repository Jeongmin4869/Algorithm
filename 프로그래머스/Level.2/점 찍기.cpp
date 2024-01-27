#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long dd = (long long)d*d;
    // x로 y의 최대값 구하기
    for(long long x=0 ; x<=d; x+=k){
        long long y = floor(sqrt(dd - (x*x)));
        answer += (y/k)+1;
    }
    
    return answer;
}
