#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//A로 전부 시작

int sol1(char c, vector<char> al){ // c가 목표알파벳
    int val = 0;
    int p2 = find(al.begin(), al.end(),c) - al.begin();
    p2 = al.size() - p2;
    return p2;
}

int solution(string name) {
    int answer = 0;
    int count = -1;
    int a_count = 0;
    int len = 0;
    int max_a=0, max_l = 0;
    //vector<char> v;
    vector<char> al = {'A','B','C','D','E','F','G','H','I','J','K','L','M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    //정방향 ... 
    //가장 큰 A배열 eln 구해서 나중에 len -1 을 정방향으로 구한거에서 빼주기
    for(int i=0; i<name.size(); i++){
        
        if(name[i] == 'A'){
            a_count++;
            if(len == -1) len = i;
        }
        else {
            if(len <= a_count){
                if(max_a<a_count){
                    max_a = a_count;
                    max_l = len;
                }
            }
            a_count = 0;
            len = -1;
        }

        count ++; // 커서이동
        int num1, num2;
        num1 = find(al.begin(), al.end(),name[i]) - al.begin();
        num2 = sol1( name[i], al);
        count = count + min(num1, num2);
        //v.push_back(name[i]);
    }
    
    if(max_a != 0 && max_l > 0){
        cout << max_a << endl;
        cout << max_l << endl;
        count = count - max_a + max_l -1;
    }
    else if (max_a != 0 && max_l == 0){
        count = count - max_a + 1;
    }
    
    
    return count;
}
