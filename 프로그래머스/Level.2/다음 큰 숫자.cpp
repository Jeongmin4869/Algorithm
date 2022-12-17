#include <string>
#include <vector>

using namespace std;

int getOneCount(int num){
    int num_count = 0;
    while(num > 0){
        if(num % 2 == 1) num_count ++;
        num /= 2;
    }
    return num_count;
}

int solution(int n) {
    int count = 0;
    int answer = 0;

    count = getOneCount(n);
    
    for(int i = n+1 ; ;i++){
        int i_count = getOneCount(i);
        if(i_count == count ) {
            answer = i;
            break;
        }
    }
    
    return answer;
}
