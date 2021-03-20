#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue <int, greater<int>> cards;
int main() {
	int N = 0;
	cin >> N;

	int n = 0, cmp = 0;
	for (int i = 0; i < N; i++) {
		cin >> n;
		cards.push(n);
	}

	if (N > 1) {
		cout << cards.top();
		
	}
	
	cout << cmp;
	return 0;
}