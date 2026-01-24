#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		if (arr[minIndex] < arr[i]) {
			int t = arr[i]; arr[i] = arr[minIndex]; arr[minIndex] = t;
		}
	}
}

int main(void) {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	selectionSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;
	return 0;
}