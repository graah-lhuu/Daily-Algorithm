#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}//此时有三个分区，小于区，大于区，还有基准，所以要将大于区的第一个元素和基准交换位置
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi+1, high);
	}
}

int main(void) {
	int n;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	quickSort(arr, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	delete[] arr;//必须手动释放内存
	return 0;

}

