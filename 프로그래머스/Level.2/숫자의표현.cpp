#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num = 0;
    for(int i=1; i<=n; i++){
        int j = i;
        while(num <= n){
            if(num == n) answer ++;
            num += j++;
        }
        num = 0;
    }
    return answer;
}
