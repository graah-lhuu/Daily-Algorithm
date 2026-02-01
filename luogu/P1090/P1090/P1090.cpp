#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	// 使用最小堆（优先队列）存储果子堆
	// greater<int>表示小顶堆，即堆顶是最小值
	priority_queue<int, vector<int>, greater<int>> minHeap;

	// 读取并构建最小堆
	for (int i = 0; i < n; i++) {
		int weight;
		cin >> weight;
		minHeap.push(weight);
	}

	long long tiredness = 0;  // 使用long long防止溢出

	// 每次合并最小的两堆，直到只剩一堆
	while (minHeap.size() > 1) {
		// 取出最小的两堆
		int first = minHeap.top();
		minHeap.pop();
		int second = minHeap.top();
		minHeap.pop();

		// 合并这两堆
		int newHeap = first + second;

		// 累加体力耗费
		tiredness += newHeap;

		// 将新堆加入优先队列
		minHeap.push(newHeap);
	}

	cout << tiredness << endl;

	return 0;
}