#include <string>
#include <vector>
#include <sstream>
#include <stack>


using namespace std;
//달받은 수식에 포함된 연산자의 우선순위를 자유롭게 재정의하여 만들 수 있는 가장 큰 숫자를 제출하는 것
//음수라면 해당 숫자의 절댓값으로 변환하여 제출
//연산 뒤에 피연산자가 음수인 연산을 처리하는 +와 * 연산을 한개식 더 정의
//6가지 경우의 수

//스택에 숫자와 연산자를 넣다가, 현재 계산해야 하는 연산자 일 시 
// 숫자 스택에 위의 2개, 연산자 스택의 위의 1개가 현재 계산해야 하는 식 이다
int dfs(string expression){
    int n;
    return n;
}

int calc(int a, int b, char ch){
    int n;
    switch(ch){
        case '-':
            n = a-b;
            break;
        case '+':
            n = a+b;
            break;
        case '*':
            n = a*b;
            break;
    }
    return n;
}

long long solution(string expression) {
    //순서 벡터? //숫자따로 char 따로??
    vector<vector <char>> priors = {{'-', '+', '*'},{'-', '*', '+'},
                                    {'+', '-', '*'}, {'+', '*', '-'},
                                    {'*', '-', '+'}, {'*', '+', '-'}};
    
    int max_val = 0;
    int val;
    int num;
    char sign;
    stack<int> dial;
    stack<char> ca;
    
    for(auto prior : priors){
        //while 문자열 자르기
        stringstream ss(expression);
        
        for(int i=0; i<prior.size(); i++){
            ss>dial;
            ss>ca;
            
        
        }
        
        if(val > max_val) max_val = val;        
    }
    
    long long answer = 0;
    return answer;
}
