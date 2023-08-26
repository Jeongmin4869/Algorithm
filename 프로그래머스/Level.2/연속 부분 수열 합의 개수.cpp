#include <string>
#include <vector>
#include <set>
#include <numeric>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    vector<int> nums = elements;
    for(int i=0; i<elements.size()-1; i++){
        nums.push_back(elements[i]);
    }
    
    for(int i=1; i<=elements.size(); i++){
        for(int j=0; j<elements.size(); j++){
            int sum = accumulate(nums.begin()+j, nums.begin()+j+i, 0);
            s.insert(sum);
        }
    }
    
    answer = s.size();
    return answer;
}
