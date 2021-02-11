#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int N, W;
int* dp;

int main() {
	cin >> N >> W;

	vector< pair<int, int> > vec(N);
	for (int i = 0; i < N; i++)
		cin >> vec[i].first >> vec[i].second;

	return 0;
}