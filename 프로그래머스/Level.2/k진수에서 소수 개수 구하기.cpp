#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool prime(long long n){
    
    if(n<2) return false;
    
    for(long long i=2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;    
    string s = "";
    
    // 1. n 을 k 진수로 변환한다.
    while(n>0){
        s = to_string(n%k) + s;
        n /= k;
    }
    s += "0";
    string temp = "";
   
    for(long long i=0; i<s.length(); i++){
        // 2. k진수로 변환된 n을 0을 기준으로 나누어준다.
        if(s[i] == '0'){
            // 3. 나누어진 수가 소수일 경우 answer 에 1을 더해준다. 
            if(temp != "" && prime(stoll(temp))){
                answer += 1;
            }
            temp = "";
            continue;
        }
        temp += s[i];
    }  
    return answer;
}
