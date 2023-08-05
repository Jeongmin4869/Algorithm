#include <string>
#include <vector>
#include <map>
using namespace std;

// 1 ≤ DD ≤ 28

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> t;
    
    for(int i=0; i<terms.size(); i++){
        string month = terms[i].substr(2, terms[i].size()-2);
        t[terms[i][0]] = stoi(month);
    }
    
    int tyear = stoi(today.substr(0,4));
    int tmonth = stoi(today.substr(5,2));
    int tday = stoi(today.substr(8,2));
    int ttotal = tyear*10000 + tmonth*100 + tday;
    
    for(int i=0; i<privacies.size(); i++){
        int year = stoi(privacies[i].substr(0,4));
        int month = stoi(privacies[i].substr(5,2));
        int day = stoi(privacies[i].substr(8,2));

        month += t[privacies[i][privacies[i].size()-1]];
                
        if(month > 12){
            if(month % 12 == 0){
                year += (month-1)/12;
                month = 12;
            }
            else {
                year += month/12;
                month %= 12;
            }
        }

        int total = year*10000 + month*100 + day;

        if(ttotal >= total) answer.push_back(i+1);
        
    }
    
    return answer;
}
