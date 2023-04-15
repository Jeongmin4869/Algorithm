#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<char, int> Xmap;
    map<char, int> Ymap;
    
    for(int i=0; i<X.size(); i++) Xmap[X[i]]++;
    for(int i=0; i<Y.size(); i++) Ymap[Y[i]]++;
    
    for(int i=9; i>=0; i--){
        int minVal = min(Xmap[i+'0'], Ymap[i+'0']);
        while(minVal > 0){
            minVal--;
            answer += to_string(i);
        }
    }
    
    if(answer == "") return "-1";
    if(answer[0] == '0') return "0";
    return answer;

}
