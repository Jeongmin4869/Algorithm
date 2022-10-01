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
