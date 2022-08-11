#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int sol1(char c, string al){ 
    int val = 0;
    int p2 = find(al.begin(), al.end(),c) - al.begin();
    if(p2 > al.size()/2){
        p2 = al.size() - p2;
    }
    return p2;
}

int solution(string name) {
    int answer = 0;
    int idx, move = 0;
    int l_len = 0, r_len = 0;
    string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 1. 가장 긴 A len 구하기
    move = name.size() -1; // 정방향
    for(int i=0; i<name.size(); i++){
        idx = i+1;
        while(name[idx] == 'A'){
            idx++;
        }
        l_len = i; 
        r_len = name.size() - idx;
        move = min(move, l_len *2 + r_len ); // 정방향 -> 반대
        move = min(move, r_len *2 + l_len ); // 반대 -> 정방향
    }
    
    //4. 세로이동방향 구하기
    for(auto c : name){
        move += sol1(c, al);
    } 
    
    return move;
}
