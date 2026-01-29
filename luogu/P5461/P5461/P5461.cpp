#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void pardon(int x, int y, int size, vector<vector<int>>& matrix) {
	if (size == 1) return;
	int half = size / 2;

	for (int i = x; i < x + half; i++) {
		for (int j = y; j < y + half; j++) {
			matrix[i][j] = 0;
		}
	}

	pardon(x + half, y, half, matrix);
	pardon(x, y + half, half, matrix);
	pardon(x + half, y + half, half, matrix);
}

int main(void) {
	int n;
	cin >> n;
	int size = pow(2, n);
	vector<vector <int>> matrix(size, vector<int>(size, 1));

	pardon(0, 0, size, matrix);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << matrix[i][j];
			if (j < size - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}