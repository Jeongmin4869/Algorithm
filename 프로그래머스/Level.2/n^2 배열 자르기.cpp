/****  효율성 0 ****/
/*
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    int num = 1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j < num){
                answer.push_back(num);
            }
            else {
                int back = answer[i*n+j-1];
                answer.push_back(back+1);
            }
        }
        num++;
    }
    
    vector<int> v;
    for(long long i=left; i<=right; i++){
        v.push_back(answer[i]);
    }
    return v;
}
*/


/**** 효율성 통과 풀이 ****/

#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    
    int num = left/(long long)n;
    for(long long i=left; i<=right; i++){
        if(i%n <= num) answer.push_back(num+1);
        else answer.push_back(i%n+1);
        
        if(i%n == n-1) num++;
    }
    return answer;
}
