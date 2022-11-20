/* 효율성 불합 코드 */
/*

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> people, int limit) {
    int count = 0;
    int sum = 0;
    
    sort(people.begin(), people.end());
    
    if(people[0] + people[1] > limit ) return people.size();    
    
    while (people.size()>0){
        sum += people[people.size()-1];
        people.erase(people.end()-1);
        
        if(people.size() !=0) {
            if(sum + people[0] <= limit){
                sum += people[0];
                people.erase(people.begin());
            }
        }

        count ++;
        sum = 0;
    }
    return count;
}
*/

/* 효율성 통과 코드 */
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(vector<int> people, int limit) {
    int count = 0;
    
    int end = people.size()-1;
    int begin = 0;
    
    sort(people.begin(), people.end()); // 몸무게 낮은 순
    
    if(people[0] + people[1] > limit ) return people.size();    
    
    while (begin <= end){
        
        if(people[end] <= limit/2){
            count += ceil((end-begin+1)/2.0);
            break;
        }
        
        if(people[end--] + people[begin] <= limit){
            begin++;
        }
        
        count ++;
    }
    
    return count;
}

