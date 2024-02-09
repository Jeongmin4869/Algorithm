#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>


using namespace std;

// 1. Greedy

// picks는 [dia, iron, stone]과 같은 구조
// 광물은 주어진 순서대로만 캘 수 있습니다.
// 각 곡괭이는 종류에 상관없이 광물 5개를 캔 ../후에는 더 이상 사용할 수 없습니다.
// 최소한의 피로도로 광물을 캐려고 합니다.

struct Mine
{
    int dia = 0;
    int irn = 0;
    int stn = 0;
    int max = 0;
};

bool cmp(Mine a, Mine b){
    return a.max > b.max;
}

int solution(vector<int> picks, vector<string> minerals) {
    int energy[3][3] = {{1,1,1},{5,1,1},{25,5,1}};
    int maxMine = 0; // 캘 수 있는 광물의 최대 수
    int now = 0, answer = 0;
    vector<Mine> mines;
    map<string, int> m;
    m.insert({"diamond", 0});
    m.insert({"iron", 1});
    m.insert({"stone", 2});
    
    for(int i=0; i<picks.size(); i++){
        maxMine += picks[i]*5;    
    }   
    
    for(int i=0; i<minerals.size(); i+=5){
        Mine mm;
        for(int j=0; j<5; j++){
            if((i+j) == minerals.size() || (i+j) == maxMine) break;
            mm.dia += energy[0][m[minerals[i+j]]];
            mm.irn += energy[1][m[minerals[i+j]]];
            mm.stn += energy[2][m[minerals[i+j]]];
            mm.max += energy[2][m[minerals[i+j]]];
        }
        mines.push_back(mm);
    }
    
    sort(mines.begin(), mines.end(), cmp);
    
    for(int i=0; i<mines.size(); i++){
        if(picks[0] > 0){
            answer += mines[i].dia;
            picks[0] -= 1;
        }
        else if (picks[1] > 0){
            answer += mines[i].irn;
            picks[1] -= 1;
        }
        else if (picks[2] > 0){
            answer += mines[i].stn;
            picks[2] -= 1;
        }
        else break;
    }
    
    return answer;
}
