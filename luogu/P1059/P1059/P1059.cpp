#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int repe = 0;
	int* flag = new int[n];

	flag[0] = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1]) {
			flag[i] = 0;
			repe++;
			continue;
		}
		flag[i] = 1;
	}

	cout << n - repe << endl;
	for (int i = 0; i < n; i++) {
		if (flag[i]) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;
	delete[] arr;
	delete[] flag;

	return 0;
}