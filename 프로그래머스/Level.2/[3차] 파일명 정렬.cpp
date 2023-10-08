#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// 파일명의 HEAD 부분이 대소문자 차이 외에는 같을 경우, NUMBER의 숫자 순으로 정렬한다. 
// 두 파일의 HEAD 부분과, NUMBER의 숫자도 같을 경우, 원래 입력에 주어진 순서를 유지한다.
// * 간과했던 부분 : TAIL은 그 나머지 부분으로, 여기에는 숫자가 다시 나타날 수도 있으며, 아무 글자도 없을 수 있다.
bool cmp(vector<string> v1, vector<string>v2){
    if(v1[0] == v2[0]) return stoi(v1[1]) < stoi(v2[1]);
    return v1[0] < v2[0];
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<vector<string>> file;
    string head, number;
    
    for(int i=0; i<files.size(); i++){
        head = "";
        number = "";
        
        for(int j=0; j<files[i].size(); j++){
            if(files[i][j]>= '0' && files[i][j] <= '9'){
                number += files[i][j];
                if(j+1 == files[i].size() || (files[i][j+1] < '0' || files[i][j+1] > '9')) {
                    vector<string> v;
                    v.push_back(head);
                    v.push_back(number);
                    v.push_back(files[i]);
                    file.push_back(v);
                    break;
                } 
            }
            else {
                head += tolower(files[i][j]);
            }
        }  
    }

    stable_sort(file.begin(), file.end(), cmp); // stable_sort는 기존 순서를 보장
    
    for(int i=0; i<file.size(); i++){
        answer.push_back(file[i][2]);
    }
    
    return answer;
}
