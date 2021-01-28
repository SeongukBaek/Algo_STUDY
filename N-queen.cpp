#include <iostream>
#include <vector>

using namespace std;
void queen(int, vector<int>&);
int place(int, int, vector<int>&);

int N, cnt;

int main()
{	
	cin >> N;
	vector<int> arr(N);

	queen(0,arr);

	cout << cnt;
	return 0;
}

void queen(int row, vector<int> &arr)
{
	int col;
	for (col = 0; col < N; col++)
	{
		if (place(row, col,arr))
		{
			arr[row] = col;
			if (row == N - 1)
				cnt++;
			else
				queen(row + 1,arr);
		}
	}
}

int place(int row, int col, vector<int>& arr)
{
	int i;
	for (i = 0; i < row; i++)
	{
		if (arr[i] == col)
			return 0;
		else
		{
			if (arr[i] - col < 0 && i - row < 0)
			{
				if (col - arr[i] == row - i)
					return 0;
			}
			else if (arr[i] - col < 0 && i - row>0)
			{
				if (col - arr[i] == i - row)
					return 0;
			}
			else if (arr[i] - col > 0 && i - row < 0)
			{
				if (arr[i] - col == row - i)
					return 0;
			}
			else if (arr[i] - col > 0 && i - row > 0)
			{
				if (arr[i] - col == i - row)
					return 0;
			}
		}
	}
	return 1;
}
