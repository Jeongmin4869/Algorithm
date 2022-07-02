#include <string>
#include <vector>
#include <sstream>
#include <stack>


using namespace std;

long long  calc(long long a, long long b, char c){
    long long n = 0;
    switch(c){
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
    
    long long max_val = 0;
    long long val = 0;
    long long  num;
    char sign;
    
    stack<long long > num_s;
    stack<char> sign_s;
    vector<long long > num_v;
    vector<char> sign_v;
    
    vector<long long > v1; // 숫자 
    vector<char> v2; // 부호
                
    //각각의 배열에 넣기
    string ex = expression;
    stringstream ss(ex);
    while(ss){ 
        if(ss >> num) {
            v1.push_back(num);
        }
        if(ss >> sign){
            v2.push_back(sign);
        }  
    }
        
    
    
    for(auto prior : priors){
        
        num_v = v1;
        sign_v = v2;
        
        while(num_v.size() > 1){
            for(int i=0; i<prior.size(); i++){
            //계산
                num_s.push(num_v[0]);
                for(int k=0; k<sign_v.size(); k++){
                    num_s.push(num_v[k+1]);
                    sign_s.push(sign_v[k]);
                    if(sign_s.top() == prior[i]){
                        long long n2 = num_s.top();
                        num_s.pop();
                        long long n1 = num_s.top();
                        num_s.pop();
                        char ci = sign_s.top();
                        sign_s.pop();
                        num_s.push(calc(n1,n2,ci));  
                    }
                }
                //스택에 있는 자료들을 배열로 옮기기
                num_v.clear(); // 초기화
                sign_v.clear();
                while(!num_s.empty()){
                    num_v.insert(num_v.begin(),num_s.top());
                    num_s.pop();
                }
                
                while(!sign_s.empty()){
                    sign_v.insert(sign_v.begin(),sign_s.top());
                    sign_s.pop();
                }
            }
        }    
        val = labs(num_v[0]);
        if(max_val < val) max_val = val;
        num_v.clear();
    }
    return max_val;
}
