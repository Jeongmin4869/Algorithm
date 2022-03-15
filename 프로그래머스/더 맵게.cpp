#include <string>
#include <vector>
#include <queue> //heap 구현
//#include <cstdio>        // less
#include <functional>    // greater

using namespace std;
//우선순위 큐를 사용
//우선순위란?
//최소 힙이란?
//왜 배열대신 우선순위 큐를 사용했는가?

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	sort(scoville.begin(), scoville.end());
	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}

	while (pq.top() < K) {
		if (pq.size() <= 1) return -1;
		int n = pq.top(); pq.pop();
		pq.push(n + pq.top() * 2); pq.pop();
		answer++;
	}

	return answer;
}