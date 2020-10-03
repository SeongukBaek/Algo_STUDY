#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <string>
//문자열로 바꿔서 각 자리 sum
using namespace std;

int strsum(string);
int N;

int strsum(int i)
{
	string strnum = to_string(i);
	int sum = i;
	
	for (char ch : strnum)
		sum += ch - '0';
	if (sum != N)
	{
		if (i == N)
			return 0;
		else
			return strsum(++i);
	}
	else
		return i;
}

int main()
{	
	cin >> N;
	cout << strsum(1);
	return 0;
}