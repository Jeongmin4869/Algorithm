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
    
    string str = "";
    
    for(int i=0; i<msg.length();){
        
        str = "";
        while(i<msg.length() && m.find(str+msg[i]) != m.end()){
            str += msg[i++];
        }
        answer.push_back(m[str]);
        if(i<msg.length()) m[str+msg[i]] = m.size() + 1;

    }
    return answer;
}
