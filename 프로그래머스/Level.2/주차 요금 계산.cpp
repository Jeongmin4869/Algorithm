#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string ,int> m;
    map<string ,int> totalTime;
    for(int i=0; i<records.size(); i++){
        string num = records[i].substr(6, 4);
        if(records[i][11] == 'I') {// IN
            int time =(records[i][0]-'0') * 60 * 10 
                      + (records[i][1]-'0') * 60 
                      + (records[i][3]-'0') * 10 
                      + (records[i][4]-'0');
            m[num] = time;
        }
        else { // out
            int time =(records[i][0]-'0') * 60 * 10 
                      + (records[i][1]-'0') * 60 
                      + (records[i][3]-'0') * 10 
                      + (records[i][4]-'0');
            int ttime  = time - m[num];
            totalTime[num] += ttime;
            m[num] = -1;
        }
    }
    
    for (auto iter : m) {
	    if(iter.second != -1){
            int time = 23*60 + 59;
            int ttime  = time - iter.second;
            totalTime[iter.first] += ttime;
        }
    }
    
    for (auto iter : totalTime) {
        int totalFee = 0;
        if(iter.second > fees[0]){
            totalFee = ceil((double)(iter.second-fees[0])/fees[2])*fees[3];
        }
        totalFee += fees[1];
        answer.push_back(totalFee);
    }
    
    return answer;
}
