#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i=0; i<skill_trees.size(); i++){
        map<char, int> m ;
        answer += 1;
        for(int j=0; j<skill_trees[i].size(); j++){
            
            if(find(skill.begin(), skill.end(), skill_trees[i][j]) == skill.end())
                continue;
            
            int index = find(skill.begin(), skill.end(), skill_trees[i][j]) - skill.begin();
            if(index != 0){
                if(m[skill[index-1]] < 1) {
                    answer -= 1;
                    break;
                }
            }
            m[skill[index]] += 1;
        }
    }
    return answer;
}
