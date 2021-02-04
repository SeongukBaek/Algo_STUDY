#include <iostream>
#include <algorithm>
//기저사례찾기 어려움, 반례 많이 필요 ...
using namespace std;

int N, idx = 0;
int* dp;

int main() {
	string str1, str2;
	int n, n1, n2, start = 0, max = 0;

	cin >> str1;
	cin >> str2;

	n1 = str1.size();
	n2 = str2.size();

	if (n1 > n2)
		n = n1;
	else
		n = n2;

	dp = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		dp[i] = 0;
	
	for (int i = 0; i < n1; i++) {
		for (int j = start; j < n2; j++) {
			if (str1[i] == str2[j]) {
				if (j != n2 - 1) {
					dp[idx + 1] = dp[idx] + 1;
					start = j + 1;
					if (max < dp[idx + 1])
						max = dp[idx + 1];
				}
				idx++;
				break;
			}
		}
	}

	/*for (int i = 0; i < n + 1; i++)
		cout << dp[i] << " ";*/
	cout << max;

	delete[] dp;
	return 0;
}