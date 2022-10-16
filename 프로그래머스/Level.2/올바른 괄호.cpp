#include<string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stack;
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == '('){
            stack.push(s[i]);
        }
        else{
            if(stack.empty()){
                return false;
            } 
            else{
                stack.pop();
            }
        }
    }
    
    return stack.empty();
}
