#include <iostream>
#include <cstring>
#include <cstdio>
//주어지는 카드 중 3장을 뽑아 
//주어진 숫자를 넘지 않는 최대의 합을 구하는 문제
//->삼중 for문으로 주어진 숫자를 넘지 않으면서 최대인 값을 max에 계속 저장
using namespace std;

void countsum(int* list, int size, int sum)
{
	int max = 0;

	for (int i = 0; i < size-2; i++)
	{
		for (int j = i + 1; j < size-1; j++)
		{
			for (int k = j + 1; k < size; k++)
			{
				if ((list[i]+list[j]+list[k]) >= max && sum >= (list[i] + list[j] + list[k]))
					max = list[i] + list[j] + list[k];
			}
		}
	}
	cout << max;
}

int main()
{
	int cardN, sum;
	int inputC[100];

	cin >> cardN >> sum;

	for (int i = 0; i < cardN; i++)
		cin >> inputC[i];

	countsum(inputC, cardN, sum);
	return 0;
}