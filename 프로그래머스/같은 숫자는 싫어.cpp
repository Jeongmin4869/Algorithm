#include <vector>
#include <iostream>
#include <algorithm> // unique 
using namespace std;

vector<int> solution(vector<int> arr)
{
	/*
	vector<int> answer(1,arr[0]);
	for(int i=1; i<arr.size(); i++){
		if(answer.back() != arr[i]) answer.push_back(arr[i]);
	}
	*/
	vector<int> answer;
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	return answer = arr;
}