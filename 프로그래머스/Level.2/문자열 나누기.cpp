#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    char c = s[0];
    int scount = 1, ocount = 0;
    
    /* ----------------------------------------------------------
    객체 접근할 때 coredump가 안 나길래 찾아봤는데 
    string 도 vector처럼 용량이 추가되거나 줄어들 것을 고려하여 용량을 할당받다고 한다. 
    ----------------------------------------------------------- */
    cout <<  "용량 : " <<  s.capacity() << endl; 
    
    
    for(int i=1; i<s.length(); i++){
        
        c == s[i] ? scount++ : ocount++;
        
        if(scount == ocount){
            scount = 0;
            ocount = 0;
            answer ++;
            c = s[i+1];
        }
    }
    
    if(scount > 0) answer ++ ;

    return answer;
}
