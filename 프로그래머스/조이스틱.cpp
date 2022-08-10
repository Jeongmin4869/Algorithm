#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int sol1(char c, string al){ // c가 목표알파벳
    int val = 0;
    int p2 = find(al.begin(), al.end(),c) - al.begin();
    if(p2 > al.size()/2){
        p2 = al.size() - p2;
    }
    return p2;
}


int solution(string name) {
    int answer = 0;
    int count = 0;
    int a_len = 0, max_a_len = 0;
    int a_idx = 0;
    string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 1. 가장 긴 A len 구하기
    
    for(int i=0; i<name.size(); i++){
        int idx = i+1;
        while(name[idx] == 'A'){
            idx++;
        }
    }
    

    //4. 세로이동방향 구하기
    for(auto c : name){
        count += sol1(c, al);
    } 
    
    return count;
}
