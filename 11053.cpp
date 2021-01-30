#include <iostream>
#include <algorithm>

using namespace std;

int dp_incr(int idx);
void dp_long(int idx);
int min(int value, int idx);

int N, max_cnt = 1;
int* arr;
int dp[1000]; //idx: arr 값, dp[idx]: 최장 수열 길이

int main() {
	cin >> N;

	arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
		dp_long(i);

	cout << max_cnt;

	delete[] arr;
	return 0;
}

int dp_incr(int idx) {
	int index = 0;
	if (index != -1)
		return index = min(arr[idx], idx);
	else
		return 0;
}

int min(int v, int idx) {
	int min = 1001, index = -1;
	for (int i = idx + 1; i < N; i++) {
		if ((arr[i] > v) && (arr[i] < min)) {
			min = arr[i];
			index = i;
		}
	}
	return index;
}

void dp_long(int idx) {
	int cnt = 1;
	if (dp[arr[idx]] == 0) {
		int num = arr[idx];
		for (int i = idx + 1; i < N; i++) {
			if (num < arr[i]) {
				cnt++;
				num = arr[i];
			}
		}
		dp[arr[idx]] = cnt;
	}
	else {
		if (N - idx > dp[arr[idx]]) { //남은 길이가 이미 저장된 값보다 큰 경우에만 실행
			int num = arr[idx];
			for (int i = idx; i < N; i++) {
				if (num < arr[i]) {
					cnt++;
					num = arr[i];
				}
			}
			if (dp[arr[idx]] < cnt)
				cnt = dp[arr[idx]];
		}
	}
	if (max_cnt < cnt)
		max_cnt = cnt;
}