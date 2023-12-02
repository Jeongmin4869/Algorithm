#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 투포인터

int solution(vector<int> queue1, vector<int> queue2) {
    long long answer = 0;
    long long sum1 = 0, sum2 = 0;
    vector<int> q;
    
    for(int num : queue1){
        q.push_back(num);
        sum1 += num;
    }
    for(int num : queue2){
        q.push_back(num);
        sum2 += num;
    }
    
    long long half =(sum1 + sum2) / 2;
    int i = 0, j = queue1.size();
    
    while(i < q.size() && j < q.size()){
        
        if(sum1 == half) return answer;
        
        if(sum1 < half){
            sum1 += q[j];
            j += 1;
        }
        else if(sum1 > half) {
            sum1 -= q[i];
            i += 1;
        }
        answer += 1;
    }
    
    return -1;
}
