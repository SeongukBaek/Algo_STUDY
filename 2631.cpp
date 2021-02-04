#include <iostream>
#include <algorithm>

using namespace std;

int N, cnt = 0;
int* arr;
int* dp;

int main() {
	cin >> N;

	arr = new int[N];
	dp = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	sort(dp, dp + N);

	cout << dp[N - 1];

	delete[] arr;
	delete[] dp;
	return 0;
}