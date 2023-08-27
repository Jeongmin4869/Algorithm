#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string str1 = s;
    string str2 = str1;
    for(int i=0; i<s.length(); i++){
        int len = 0;
        str2 = str1;
        while (true){
            len = str2.length();
            
            if(str2.find("()") != string::npos) str2.replace(str2.find("()"), 2,"");
            if(str2.find("[]") != string::npos) str2.replace(str2.find("[]"), 2,"");
            if(str2.find("{}") != string::npos) str2.replace(str2.find("{}"), 2,"");

            if(str2.length() == 0){
                answer += 1;
                break;
            }
            if(len == str2.length())
                break;
        }
        str1 = str1 + str1[0];
        str1 = str1.substr(1, str1.length()-1);
    }

    return answer;
}
