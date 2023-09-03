/*
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

// 슬라이딩 윈도우 알고리즘
// number의 원소의 합은 10
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    for(int k=0; k<10; k++){
        m[discount[k]] += 1;
    }
    
    for(int i=0; i<=discount.size()-10; i++){
        bool signin = true;
        for(int j=0; j<want.size(); j++){
            if(m[want[j]] != number[j]){
                signin = false;
                break;
            }
        }
        
        if(!signin && 10+i < discount.size()){
            m[discount[i]] -= 1;
            m[discount[i+10]] += 1;
        }
        else if(signin){
            answer += 1;
        }
    }
    // 원하는 제품을 모두 할인 받을 수 있는 회원등록 날짜의 총 일수
    return answer;
}

*/


#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i=0; i<=discount.size()-10; i++){
        bool signin = true;
        
        map<string, int> m;
        for(int start=0+i; start<10+i; start++){
            m[discount[start]] += 1;
        }
        
        for(int j=0; j<want.size(); j++){
            if(m.count(want[j]) == 0 || m[want[j]] != number[j]){
                signin = false;
                break;
            }
        }

        if(signin){
            answer += 1;
        }
    }
    // 원하는 제품을 모두 할인 받을 수 있는 회원등록 날짜의 총 일수
    return answer;
}
