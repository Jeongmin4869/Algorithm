#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    // 1. 우박수열 구하기
    vector<double> v, answer;
    vector<double> areas;
    int num = k;
    while(1){
        v.push_back(num);
        if(num == 1) break;
        num = num%2==0?num/2:num*3+1;
    }
    
    for(int i=0; i<v.size()-1; i++){
        double area = (v[i]+v[i+1])/2.0;
        areas.push_back(area);
    }
    
    // 주어진 구간의 시작점이 끝점보다 커서 유효하지 않은 구간이 주어질 수 있으며 이때의 정적분 결과는 -1로 정의
    for(int i=0; i<ranges.size(); i++){
        double s = ranges[i][0];
        double e = (double)areas.size()+ranges[i][1];
        double sum = 0;
        if(s>e || s>areas.size()){
            answer.push_back(-1);
            continue;
        }
        for(int j=s; j<e; j++){
            sum += areas[j];
        }
        answer.push_back(sum);
    }
    
    return answer;
}
