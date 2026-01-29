#include <iostream>

using namespace std;

int main(void) {
	long long int n, m;
	cin >> n >> m;
	long long int square, rectangle;
	rectangle = (m + 1) * m /2 * (n + 1) * n / 2;

	if (n < m) swap(n, m);//Make sure that n>=m
	square = 0;
	for (int i = 1; i <= m; i++) {
		square += (m - i + 1) * (n - i + 1);
	}
	rectangle -= square;

	cout << square << " " << rectangle << endl;

	return 0;
}