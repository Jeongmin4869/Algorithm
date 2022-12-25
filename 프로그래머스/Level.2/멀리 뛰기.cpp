#include <string>
#include <vector>

using namespace std;

/*
[n - 1]번째 칸에서 1칸을 뛰어서 n번째 칸에 도착했다.
[n - 2]번째 칸에서 2칸을 뛰어서 n번째 칸에 도착했다.
*/


long long solution(int n) {
    long long head = 0;
    long long tail = 1;
    long long temp;
    
    if(n==0) return 0;
    
    for(int i=1; i<=n; i++){
        temp = tail;
        tail += head%1234567;
        head = temp;
    }
    return tail%1234567 ;
}
