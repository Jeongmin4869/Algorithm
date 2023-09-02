#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = -1;
    // vector는 대입 연산자를 통해 깊은복사 
    vector<int> prearr = arr;
    vector<int> nowarr = arr;
    
    while(true){
        answer += 1;
        for(int i=0; i<nowarr.size(); i++){
            if(nowarr[i]%2==0 && nowarr[i]>=50) nowarr[i] /= 2;
            else if(nowarr[i]%2!=0 && nowarr[i]<50) nowarr[i] = nowarr[i] * 2 + 1;
        }
        if(prearr == nowarr) break;
        prearr = nowarr;
    }
    
    return answer;
}
