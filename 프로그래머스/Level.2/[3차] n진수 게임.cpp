#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
    진법 n
    미리 구할 숫자의 갯수 t
    게임에 참가하는 인원 m
    튜브의 순서 p
*/

string solution(int n, int t, int m, int p) {
    string numStr = "0123456789ABCDEF";
    string tellStr = "0";
    string answer = "";
    int count = 1;
    while(tellStr.length() < m*t){
        int num = count;
        string str = "";
        while(num > 0){
            str = numStr[num%n] + str;
            num /= n;
        }
        tellStr += str;
        count += 1;
    }
    
    for(int i=0; i<t; i++){
        answer += tellStr[(i*m)+p-1];
    }
    return answer;
}
