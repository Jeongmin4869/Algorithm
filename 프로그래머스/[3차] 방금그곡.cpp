#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

// 입력 순서를 고려하는 경우 데이터를 따로 저장하지 않고 반복문에서 바로 처리 ... 
// 조건이 일치하는 음악이 여러 개일 때에는 라디오에서 재생된 시간이 제일 긴 음악 제목을 반환한다. 
// 재생된 시간도 같을 경우 먼저 입력된 음악 제목을 반환한다.

// #이 붙은 음을 다른 문자로 치환
// 다른 문자로 치환하려 했으나 소문자처리
string changeString(string str){
    for(int i=1; i<str.size(); i++){
        if(str[i] == '#'){
            str[i-1] = str[i-1]+32;
            str.erase(str.begin()+i); // #제거
        }
    }
    return str;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int ttime = 0; // 가장 긴 재생시간을 저장
    string mm = changeString(m);

    for(int i=0; i<musicinfos.size(); i++){

        vector<string> musicinfo;
        stringstream ss(musicinfos[i]);
        string buffer;

        while(getline(ss, buffer, ',')){
            musicinfo.push_back(buffer);
        }
        
        int startT = stoi(musicinfo[0].substr(0, 2)) * 60 + stoi(musicinfo[0].substr(3, 2));
        int endT = stoi(musicinfo[1].substr(0, 2)) * 60 + stoi(musicinfo[1].substr(3, 2));
        
        int playTime = endT - startT;
        // #을 다른 문자로 치환. 치환한 후 악보의 길이 측정
        // C# : 2 -> c : 1
        string song = changeString(musicinfo[3]);
        int stime = song.size();
        
        // 재생시간에 맞추어 멜로디 조절
        if(playTime < stime){
            song = song.substr(0, playTime);
        }
        else if(playTime > stime){
            while(song.size() < playTime){
                song += song;
            }
            song = song.substr(0, playTime);
        }

        if(song.find(mm) != string::npos){
            if(ttime < playTime){
                ttime = playTime;
                answer = musicinfo[2];
            }
        }
    }
    
    return answer==""?"(None)":answer;
}
