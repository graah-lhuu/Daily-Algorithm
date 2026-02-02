#include <iostream>
#include <algorithm>
using namespace std;

struct Num {
	int id;
	int value;
};

struct Target {
	int number;
	int id;
};

/**
 * 二分查找函数 - 查找目标值在数组中第一次出现的位置
 * @param arr 有序数组
 * @param n 数组长度
 * @param k 目标值
 * @return 目标值第一次出现的1-based位置，未找到返回-1
 */
int search(Num arr[], int n, int k) {
	int high = n - 1;
	int low = 0;
	int result = -1;  // 记录找到的位置

	while (low <= high) {
		int mid = low + (high - low) / 2;  // 避免整数溢出

		if (arr[mid].value == k) {
			result = mid;      // 记录找到的位置
			high = mid - 1;    // 继续向左搜索第一次出现
		} else if (arr[mid].value < k) {
			low = mid + 1;     // 目标值在右半部分
		} else {
			high = mid - 1;    // 目标值在左半部分
		}
	}

	// 根据查找结果返回相应值
	if (result == -1) {
		return -1;             // 未找到
	} else {
		return result + 1;     // 找到，转换为1-based编号
	}
}

int main() {
	// 输入输出优化
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	// 动态分配数组
	Num* num = new Num[n];
	Target* target = new Target[m];

	// 读取序列数据
	for (int i = 0; i < n; i++) {
		cin >> num[i].value;
		num[i].id = i;  // 记录原始位置（实际未使用）
	}

	// 处理每个查询
	for (int i = 0; i < m; i++) {
		cin >> target[i].number;
		target[i].id = search(num, n, target[i].number);
	}

	// 输出结果
	for (int i = 0; i < m; i++) {
		cout << target[i].id << " ";
	}
	cout << endl;

	// 释放动态分配的内存
	delete[] num;
	delete[] target;

	return 0;
}