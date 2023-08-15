#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for(int i=0; i<array.size(); i++){
        int num = array[i];
        while(num > 0){
            if(num % 10 == 7) answer += 1;
            num /= 10;
        }
    }
    return answer;
}
