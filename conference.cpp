#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
//회의 최대 개수

bool comp(const vector<int>& a, const vector<int>& b)
{
	if (a[1] == b[1])
		return a[0] < b[0];
	return a[1] < b[1];
}

int main()
{
	int N, cnt = 1, stime = 0, ftime = 0;
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(2, 0)); //0으로 초기화된 Nx2 배열

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2; j++)
			cin >> arr[i][j];

	sort(arr.begin(), arr.end(), comp);// 두번째 열 기준 정렬

	stime = arr[0][0];
	ftime = arr[0][1];
	for (int i = 1; i < N; i++)
	{
		if (arr[i][0] >= ftime)
		{
			ftime = arr[i][1];
			cnt++;
		}
	}
	cout << cnt;
	arr.clear();
}
