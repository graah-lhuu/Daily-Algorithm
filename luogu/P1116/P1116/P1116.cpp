#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int count = 0;
	for(int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				count++;
			}
		}
	}
	cout << count;

	delete[] arr;
	return 0;
}