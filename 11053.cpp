#include <iostream>

using namespace std;

int main() {
	int N, number = 0, cnt = 0;
	cin >> N;

	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (number < arr[i]) {
			number = arr[i];
			cnt++;
		}
	}
	cout << cnt;
	delete[] arr;
	return 0;
}