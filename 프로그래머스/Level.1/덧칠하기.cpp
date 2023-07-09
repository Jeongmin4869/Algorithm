#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int paint = 0;
    for(int i=0; i<section.size(); i++){
        if(paint < section[i]){
            answer += 1;
            paint = section[i] - 1 + m; // index가 0 부터 시작하기 때문에 -1
        }
    }
    return answer;
}
