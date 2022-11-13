#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for(int i = 0; i<number.size()-1; i++){
        if(k == 0) break;
        if(number[i] < number[i+1]){
            number.erase(i, 1);
            k--;
            i==0?i-=1:i-=2; // 바로 직전 숫자와의 비교를 위해 i-=2
        }
    }
    
   // number[i] < number[i+1] 인경우가 없는 경우 뒤에서부터 숫자 제거
    if(k>0) number.erase(number.size()-k , k);
    
    return answer = number;
}
