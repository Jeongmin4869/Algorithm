#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool sosu(long long n){
    
    if(n<2) return false;
    
    for(long long i=2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;    
    string s = "";
    while(n>0){
        s = to_string(n%k) + s;
        n /= k;
    }
    string temp = "";
    
    for(long long i=0; i<s.length(); i++){
        if(s[i] == '0'){
            if(temp != "" && sosu(stoll(temp))){
                answer += 1;
            }
            temp = "";
            continue;
        }
        temp += s[i];
    }
    
    if(temp != "" && sosu(stoll(temp))) answer += 1;
  
    return answer;
}
