/* 시간초과 */
/*

#include <string>
#include <vector>

using namespace std;

int width;
int count = 0;
int num = 1000000007;

void search(int w){

    if(w == width) {
        ++count%num;
        return ;
    }
    
    if(w > width ) {
        return; 
    }
    
    search(w+1);
    search(w+2);
}

int solution(int n) {
    width = n;
    search(0);
    return count%num;
}

*/

/* dp 사용 */
#include <string>
#include <vector>

using namespace std;

// 피보나치수열
// 1 > 2 > 3 > 5 > 8 > ...
int num = 1000000007;

int solution(int n) {
    int bf = 1;
    int af = 1;
    int temp;
    for(int i=1; i<n; i++){
        temp = af;
        af = (bf + af)%num;
        bf = temp%num;
    }
    
    return af%num;
}
