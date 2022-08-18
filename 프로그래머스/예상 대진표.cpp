//#include <vector>
using namespace std;

/* 

//실행시간 오류

int solution(int n, int a, int b)
{
    int answer = 0;
    vector<int> v;
    v.assign(n, 0);
    v[a-1] = a;
    v[b-1] = b;
    bool roof = true;
    while(roof){
        answer ++;
        for(int i=0; i<v.size(); i++){
            v[i] = v[i] + v[i+1];
            v.erase(v.begin() + i + 1);
            if( v[i]  == (a + b)){
                roof = false;
                break;
            }
        }
    }
    
    return answer;
}

*/

int solution(int n, int a, int b)
{
    int answer = 0;
    while(a!=b){
        answer ++;
        if(a%2==1) a++;
        if(b%2==1) b++;
        a/=2;
        b/=2;
    }
    
    return answer;
}
