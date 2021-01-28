#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
//주어진 사람들의 돈을 인출하는데 필요한 시간의 합의 최솟값
//시간이 적게 걸리는 순으로 인출해야 최소가 됨
using namespace std;

int main()
{
	int N, sum = 0;
	cin >> N;
	vector<int> arr(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	for (int i = 0, j = N; i < N, j > 0; i++, j--)
		sum += arr[i]*j;

	arr.clear();
	cout << sum;
}