#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

/*
1) info를 파싱하는데, -를 포함한 모든 경우의 수를 map에 넣어준다. query에서 나올 수 있는 조건을 모두 map에 넣어주면 된다. 2^
2) map을 순회하면서 점수를 오름차순으로 정렬해준다. 이분 탐색을 위해 정렬이 필요하다.
3) query를 파싱하여 조건을 나타내는 문자열을 얻는다.
*/

/*
1. info 에 대해 모든 가능한 경우의 수 구하기.
2. map key를 조건, value를 점수로 해 map의 점수들을 각각 정렬하기.
3. query파싱하고, 비교하기
*/


vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(), 0);
    map<string, vector<int>> m;

    for(int i=0; i<info.size(); i++){
        int score = 0, idx = 0;
        vector<vector<string>> v(4, vector<string>(2, "-"));
        string str;
        stringstream ss(info[i]);
        while(ss >> str){
            if(idx < 4){
                v[idx++][0] = str;
            }
            else {
                score = stoi(str);
            }
        }
        

        //info의 모든 경우의 수 map
        for(int a = 0; a<v[0].size(); a++){
            string s1, s2, s3, s4;
            s1 = v[0][a];
            for(int b = 0; b<v[1].size(); b++){
                s2 = v[1][b];
                for(int c = 0; c<v[2].size(); c++){
                    s3 = v[2][c];
                    for(int d = 0; d<v[3].size(); d++){
                        s4 = v[3][d];
                        m[s1 + s2 + s3 + s4].push_back(score);
                    }
                }       
            }
        }
    }
        
    //map의 score를 정렬
    for(auto itr = m.begin(); itr != m.end(); itr++){
        sort(itr->second.begin(), itr->second.end());
    }
        
    //query 파싱, 비교
    for(int i=0; i<query.size(); i++){
        stringstream ss(query[i]);
        string str="";
        string t;
        int score, count = 0;
            
       while(ss >> str){
            
            if(str == "and") continue;
            
            if(count ++ <4){
                t += str;
            }
            else {
                score = stoi(str);
            }
        }
            
        // lower_bound : 2진탐색
        int idx = lower_bound(m[t].begin(), m[t].end(), score) - m[t].begin() ;
        answer[i] = m[t].size() - idx;
    } 
    
    return answer;
}
