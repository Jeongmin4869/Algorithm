#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "RCJA";
    vector<string> types = {"RT", "CF", "JM", "AN"};
    map<char, int> map;
    
    for(int i=0; i<survey.size(); i++){
        if(choices[i] < 4)
            map[survey[i][0]] += (4-choices[i]);
        else 
            map[survey[i][1]] += (choices[i]-4);
    }
    
    for(int i=0; i<types.size(); i++){
       if(map[types[i][0]] < map[types[i][1]])
            answer[i] = types[i][1];
    }
    
    return answer;
}
