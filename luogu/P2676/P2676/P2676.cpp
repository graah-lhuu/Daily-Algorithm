#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main(void) {
	long long int n, b;
	cin >> n >> b;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n,cmp);
	long long int sum = 0;
	int i = 0;
	while (sum < b) {
		sum += arr[i];
		i++;
	}
	cout << i << endl;

	return 0;
}