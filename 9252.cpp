#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1001][1001];

int main() {
	string str, str1, str2;
	char lcs[1000];
	int tmp = 0, idx = 0;

	cin >> str1;
	cin >> str2;

	str = str1;

	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (str1[i] == str2[j]) 
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
		if (i == str1.size() - 1) {
			if (dp[i + 1][str2.size()] > dp[i][str2.size()])
				str = str1;
			else
				str = str2;
		}
	}

	cout << dp[str1.size()][str2.size()] << endl;

	for (int i = 0; i <= str1.size(); i++) {
		for (int j = 0; j <= str2.size(); j++) {
			cout << dp[i][j];
		}
		cout << endl;
	}
	/*for (int i = str1.size(); i > 0; i--) {
		for (int j = str2.size(); j > 0; j--) {
			if (i == j) {
				if (dp[i][j] - dp[i - 1][j - 1] == 1) {
					lcs[idx++] = str[i - 1];
				}
				break;
			}
		}
	}
	for (int i = idx - 1; i >= 0; i--) {
		cout << lcs[i];
	}*/

	return 0;
}