#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 배열을 정렬한 후 이중반복문을 통해 구할 때 시간초과 

// 시소는 중심으로부터 2(m), 3(m), 4(m) 거리! 1m는 없음

// 최대공약수 : greatest common factor
long long gcd(int a, int b){
    if(a%b==0) return b;
    return gcd(b, a%b);
}

// 최소공배수 : least common multiple
long long lcm(int a, int b){
    return a*b/gcd(a,b);
}

long long solution(vector<int> weights) {
    long long answer = 0;
    long long l;
    map<int, int> map; // 기본 오름차순 정렬
    
    for(int w : weights){
        map[w]+=1;
    }
    
    for(auto i : map){
        
        // 같은 무게끼리의 짝
        for(int n=1; n<i.second; n++)
            answer += n;
        
        // 다른 무게의 짝
        for(auto j : map){
            if(i.first != j.first){
                l = lcm(j.first, i.first); // long long 
                if(l == j.first) // 최소공배수가 두 수 중 가장 큰 값과 동일할경우. 1m 의자는 없으므로 2를 곱해주어 2m지점에 착석하도록 한다.
                    l *= 2;
                if(l/i.first<=4) // j보다 i가 작은 값이므로 i로만 비교 
                    answer += i.second * j.second;
            }
        }
        // key값을 통해 erase
        map.erase(i.first);
    }
    
    return answer;
}


/*
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#include <iostream>
using namespace std;

// 최대공약수 : greatest common factor
long long gcd(int a, int b){
    if(a%b==0) return b;
    return gcd(b, a%b);
}

// 최소공배수 : least common multiple
long long lcm(int a, int b){
    return a*b/gcd(a,b);
}

long long solution(vector<int> weights) {
    long long answer = 0;
    long long a, b, l;
    
    sort(weights.begin(), weights.end());
    
    for(int i=0; i<weights.size(); i++){
        for(int j=i+1; j<weights.size(); j++){
            a = weights[j], b = weights[i];
            l = lcm(a, b);
            if(l/b <= 4) answer += 1;
        }
    }
    return answer;
}

*/
