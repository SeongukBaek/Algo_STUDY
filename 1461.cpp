#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int books[10000];
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> books[i];

	sort(books, books + N);

	return 0;
}