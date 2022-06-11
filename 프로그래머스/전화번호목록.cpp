#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end()); 
    string str;
    //이중포문은 시간초과
    //phonenumber 리스트를 값과 길이 두 가지 기준으로 정렬 하면, 반복문을 돌며 phonenumber[index] 가 phone_number[index+1]의 접두어 인지만 확인
    /*
    for(int i=0; i<phone_book.size()-1; i++){
        str = phone_book[i];
        for(int j=i+1; j<phone_book.size(); j++){ 
            if(str[0] != phone_book[j][0]) break;
            if(phone_book[j].find(str) == 0)
                return false;
        }
    }
    */
    
    for(int i=0; i<phone_book.size()-1; i++){
        if(phone_book[i+1].find(phone_book[i]) == 0)
                return false;
    }
    
    return answer;
}
