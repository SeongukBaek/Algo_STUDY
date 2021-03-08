#include <iostream>
using namespace std;

int cube();

int N;
long min_sum = 1000000000000000;
int dice[6];
int main() {
	int sum = 0;
	cin >> N;

	for (int i = 0; i < 6; i++)
		cin >> dice[i];

	if (N == 1) {
		for (int i = 0; i < 6; i++)
			sum += dice[i];
		min_sum = sum;
	}
	else {
		for (int i = 0; i < 5; i++) {
			int sum = cube();
			if (sum < min_sum)
				min_sum = sum;
		}
	}

	cout << min_sum;
	return 0;
}

int cube() {

}