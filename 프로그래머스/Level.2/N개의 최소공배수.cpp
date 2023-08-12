#include <string>
#include <vector>
using namespace std;

/*
GCD = 최대공약수
LCM = 최소공배수
*/
int gcd(int n, int m){
    if(n%m == 0) return m;
    return gcd(m, n%m);
}

int solution(vector<int> arr) {
    int answer = 0;
    int num = arr[0]; // 이전에 구한 최소공배수
    for(int i=1; i<arr.size(); i++){
        int g = gcd(num, arr[i]); // 최대공약수
        num = num*arr[i]/g; // 최소공배수
    }
    return answer = num;
}
