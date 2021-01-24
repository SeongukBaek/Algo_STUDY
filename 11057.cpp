#include <iostream>
#include <cmath>
using namespace std;
int N, ans = 0;

void countAscent(int num);

int main() {
	cin >> N;

	for (int i = 0; i < pow(10,N); i++) {
		countAscent(i);
	}

	//cout << ans % 10007;
	return 0;
}

void countAscent(int num) {
	
}