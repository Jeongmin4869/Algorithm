#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

/*
관계 데이터베이스에서 릴레이션(Relation)의 튜플(Tuple)을 유일하게 식별할 수 있는 속성(Attribute) 또는 속성의 집합 중, 다음 두 성질을 만족하는 것을 후보 키(Candidate Key)라고 한다.
- 유일성(uniqueness) : 릴레이션에 있는 모든 튜플에 대해 유일하게 식별되어야 한다.
- 최소성(minimality) : 유일성을 가진 키를 구성하는 속성(Attribute) 중 하나라도 제외하는 경우 유일성이 깨지는 것을 의미한다. 즉, 릴레이션의 모든 튜플을 유일하게 식별하는 데 꼭 필요한 속성들로만 구성되어야 한다.
*/

// 모든 조합 을 구한다. 
// 키가 되는 조합만을 남긴다. 
// 포함하는 키를 제거한다. 

vector<vector<int>> keys; 
int N;
 void dfs(int targetnum, vector<int> v, int now){
     if(v.size() >= targetnum){
        keys.push_back(v); 
        return;
     }
     
     for(int i=now; i<N; i++){
         vector<int> vec = v;
         vec.push_back(i);
         dfs(targetnum, vec, i+1);
     }
     
     return;
 }

int solution(vector<vector<string>> relation) {
    int answer = 0;
    N = relation[0].size();
    
    // 1. 모든조합구하기
    for(int i=1; i<=N; i++){
        vector<int> v;
        dfs(i, v, 0);
    }
    
    map<string, int> m;

    // 2. 유일성 확인 
    for(int i=0; i<keys.size(); i++){
        vector<int>v = keys[i];
        m.clear();
        for(int j=0; j<relation.size(); j++){
            string str = "";
            for(int k=0; k<v.size(); k++){
                str += relation[j][v[k]];
            }
            m[str] += 1;
        }
        
        if(m.size() < relation.size()){
            keys.erase(keys.begin() + i);
            i--;
        }
    }

    cout << keys.size() << endl;
    
    sort(keys.begin(), keys.end());
    
    // 3 희소성 확인
    for(int i=0; i<keys.size()-1; i++){
        for(int j=i+1; j<keys.size(); j++){
            bool flag = true;
            for(int k=0; k<keys[i].size(); k++){
                if(find(keys[j].begin(), keys[j].end(), keys[i][k]) == keys[j].end()){
                    flag = false;
                    break;
                }
            }
            
            if(flag){
                keys.erase(keys.begin() + j);
                j--;
            } 
        }
    }

    return keys.size();
}
