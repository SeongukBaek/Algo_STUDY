#include <iostream>

using namespace std;

int N;
int* nums;

void dfs(int idx);

int main() {
	cin >> N;

	nums = new int[N];
	for (int i = 0; i < N; i++)
		cin >> nums[i];

	dfs(0);

	return 0;
}

void dfs(int idx) {
	for (int i = idx; i < N; i++) {
		dfs(nums[idx]);
	}
}