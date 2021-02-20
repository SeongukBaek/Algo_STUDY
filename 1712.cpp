#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	int year = 0;
	int this_benefit = 0;

	cin >> a >> b >> c;

	while (1) {
		this_benefit = c * year - (a + b * year);
		if (year == 2) {
			int last_benefit = c * (year - 1) - (a + b * (year - 1));
			if (this_benefit - last_benefit < 0) {
				cout << "-1";
				break;
			}
		}
		if (this_benefit > 0) {
			cout << year;
			break;
		}
		year++;
	}
	return 0;
}