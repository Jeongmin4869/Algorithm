#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

//마지막 인자로 정렬
bool cmp(vector<string> &v1, vector<string> &v2){
    return stoi(v1[4]) > stoi(v2[4]);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;   
    vector<vector<string>> vfo;
    vector<vector<string>> check;
    vector<int> score;
    answer.assign(query.size(), 0);
    string str;
    
    //숫자
    
    //query문자 추출
    for(int i=0; i<query.size(); i++){
        vector<string> v;
        stringstream ss;
        ss.str(query[i]);
        while(ss >> str){
            if(str != "and"){
                v.push_back(str);
            }
        }
        check.push_back(v);
    }
    
    
    //저는 마찬가지로 query를 만들고, score를 list로 저장한 다음에 정렬했습니다.
    //info문자 추출, 점수로 오름차순 정렬
    for(int i=0; i<info.size(); i++){
        vector<string> v;
        stringstream ss;
        ss.str(info[i]);
        while(ss >> str){
                v.push_back(str);
        }
        vfo.push_back(v);
    }
    
    sort(vfo.begin(), vfo.end(), cmp);
    
    
    for(int i=0; i<check.size(); i++){
        for(int j=0; j<vfo.size(); j++){
            int count = 0;

            if(stoi(vfo[j][4]) >= stoi(check[i][4]) || check[i][4] 
               == "-")
                count++;
            else break;
            
            if(vfo[j][0] == check[i][0] || check[i][0] == "-") count++;
            if(vfo[j][1] == check[i][1] || check[i][1] == "-") count++;
            if(vfo[j][2] == check[i][2] || check[i][2] == "-") count++;
            if(vfo[j][3] == check[i][3] || check[i][3] == "-") count++;

            if(count==5) answer[i]++;
            count = 0;
        }
    }
    
    return answer;
}
