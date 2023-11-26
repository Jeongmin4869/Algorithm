#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
영역이 모두 1인경우 -> 1 개수++
영역이 모두 0인경우 -> 0 개수++
영역 내부 숫자가 다른경우 -> 4등분해서 분할정복(재귀)
*/

/*
함수를 quard_zip(a,b,c,d); 로 호출을 하게되면
호출하면서 a,b,c,d의 주소로 접근해서 값을 사용하는 것이아니라 새로운 값을 할당하여 호출하게 된다.

새로 메모리영역에 값을 할당하는 비용이 크기 때문에 함수 안에서 값을 변경하지 않을 경우 매개변수로 받은 값을 사용하는게 합리적이므로
매개변수를 참조로 호출하면 새로 메모리를 할당하지 않아 시간적 공간적 이득을 얻을 수 있습니다.

- const : 상수화
- & : 참조자

- 포인터 : 객체의 주소를 가리키는 변수
- 참조자 : 객체의 값을 담는 공간

*/

static vector<int> answer;

void quad( const vector<vector<int>> &arr,int x, int y, int n){
    int num = arr[x][y];
    int count = 0;
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(arr[i][j] != num){
                quad(arr, x    , y    , n/2);
                quad(arr, x+n/2, y    , n/2);
                quad(arr, x    , y+n/2, n/2);
                quad(arr, x+n/2, y+n/2, n/2);
                return; // 1칸이라도 다르면 다시 칸을 2로 분할
            }
            count += 1;
        }
    }
    answer[num] += 1;
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    answer = {0,0};
    int n = arr.size();
    quad(arr, 0, 0, n);
    return answer;
}
