#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0, n = nums.size() / 2;
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	return min((int)nums.size(), n);
}