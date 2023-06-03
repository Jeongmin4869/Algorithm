#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
k : 사과의 최대 점수
m : 한 상자에 들어가는 사과의 개수
score : 모든 사과가 들어있는 배열
*/

int solution(int k, int m, vector<int> score) {
    vector<int> subv;
    
    int answer = 0;
    if(score.size() < m) {
        return 0;
    }
    
    sort(score.begin(), score.end(), greater<>()); // 최대이익 구하기위해 역순정렬
    
    for(int i=0; i<score.size()-m+1; i+=m){
        vector<int> subv = {score.begin()+i, score.begin()+i+m};
        int min = subv[m-1]; // subv[m-1]번째 요소가 최저 사과 점수를 가지고있다.
        answer += min * m;
    }
    
    return answer;
}
