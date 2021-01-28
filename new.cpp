#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
//신입사원 채용하는데 한 지원자의 성적이 
//다른 지원자의 성적에 비해 서류, 면접 둘다 떨어진다면 선발 X
//vector<vector<int>> arr(N, vector<int>(2, 0));를
//vector<pair<int, int>> arr(N);로 변경
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) //서류심사성적에 대해 오름차순 정렬
{
	if (a.first != b.first)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	int T, N, cnt = 1, rank = 0, a, b;
	
	cin >> T;
	vector<int> answer; //결과 저장할 배열
	while (T--)
	{
		cin >> N;

		vector<pair<int, int>> arr(N);

		for (int i = 0; i < N; i++)
		{
			cin >> a >> b;
			arr[i] = { a,b };
		}

		sort(arr.begin(), arr.end(), comp);

		if (arr[0].first == 1 && arr[0].second == 1) //정렬 후 첫 행이 1 1이라면 더 이상의 사원 선발 X
			answer.push_back(1);
		else
		{
			rank = arr[0].second; //정렬 후 첫번째 행의 지원자는 합격, 그 다음 지원자의 면접성적 순위로 결정
			for (int i = 1; i < N; i++)
				if (rank >= arr[i].second)
				{
					rank = arr[i].second;
					cnt++;
				}
			answer.push_back(cnt);
			cnt = 1;
		}			
		arr.clear();
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
}