#include <string>
#include <vector>
#include <sstream>
#include <stack>


using namespace std;
//달받은 수식에 포함된 연산자의 우선순위를 자유롭게 재정의하여 만들 수 있는 가장 큰 숫자를 제출하는 것
//음수라면 해당 숫자의 절댓값으로 변환하여 제출
//연산 뒤에 피연산자가 음수인 연산을 처리하는 +와 * 연산을 한개식 더 정의
//6가지 경우의 수
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
    
    int max_v = 0;
    int num;
    stack<int> dial;
    stack<char> ca;
    //stack<string> ? 
    char sign;
    stringstream ss(expression);
    
    for(auto prior : priors){
        for(int i=0; i<prior.size(); i++){
        }
    }
    
    long long answer = 0;
    return answer;
}
