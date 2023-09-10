#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    for(int i=0; i<26; i++){
        string s = "";
        s = 'A'+i;
        m[s] = i+1;
    }
    
    string str1 = "", str2 = "";
    
    for(int i=0; i<msg.length(); i++){
        str2 = str1 + msg[i];
        if(m.find(str2) == m.end()){
            answer.push_back(m[str1]);
            m[str2] = m.size()+1;
            str1 = "";
            i--;
            continue;
        }
        str1 = str1 + msg[i];
    }
    answer.push_back(m[str1]);
    
    return answer;
}
