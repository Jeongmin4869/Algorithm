#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	//oneoneoneone => 1oneoneone
	int answer = 0;
	string arr[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
	//hash key가 int일바에 차라리 배열을... 
	printf("%d", sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(string); i++) {
		//if(s.find(arr[i])!= string::npos){
		   //s = s.replace(s.find(hash[i]), hash[i].length(),to_string(i));

		//}

	}

	return answer;
}