#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int sol1(char c, vector<char> al){ // c가 목표알파벳
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
    vector<char> al = {'A','B','C','D','E','F','G','H','I','J','K','L','M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    // 1. 가장 긴 A len 구하기
    for(int i=0; i<name.size(); i++){
        while(name[i] == 'A'){
            a_len ++ ;
            i++;
        }
        if(max_a_len < a_len ) {
            max_a_len = a_len;
            a_idx = i;
        }
        a_len = 0;
    }
    
    // 2. 가장 긴 A를 기준으로 왼, 오 길이 구하기
    int l_len=0, r_len=0;
    if(max_a_len == 0) l_len = name.size();
    else {
        l_len = a_idx - max_a_len;
        r_len = name.size() - a_idx;
    }
    cout << l_len << " , " << r_len << endl;
    //3가지 경우의 수 구하기. 1)순서대로 2)순서대로갔다가반대로 3)반대로갔다가순서대로
    int move = 0;
    if(max_a_len==0 || r_len == 0 && l_len > 0){
        //처음이랑 끝에 이어진게 가장 긴 경우
        count += l_len-1;
    }
    
    move = count;
    else if (l_len <= max_a_len && l_len <= r_len) {
        if(l_len == 0)  
            count += r_len;
        else
            count += (2*l_len + r_len - 2);
    }
    else if(r_len < l_len){ 
         count += (2*r_len + l_len - 1);  
    }
    

    //4. 세로이동방향 구하기
    for(auto c : name){
        count += sol1(c, al);
    } 
    
    return count;
}
