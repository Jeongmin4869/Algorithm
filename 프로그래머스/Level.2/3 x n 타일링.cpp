#include <string>
#include <vector>
#include <iostream>
using namespace std;
// mod 알고리즘
int solution(int n) {
    long long mod = 1000000007;
    vector<int> v = {0,3,11};
    if( n%2 != 0) return 0;

    for(int i=3; i<=n/2; i++){
        long long sum=0;
        sum += (v[i-1] * 3 + 2)%mod;
        for(int j=i-2; j>0; j--){
            sum += (v[j] * 2) % mod;
        }
        v.push_back(sum%mod);
    }
    
    return v[n/2]% mod;
}
