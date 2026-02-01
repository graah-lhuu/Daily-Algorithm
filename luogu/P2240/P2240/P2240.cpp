#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

// 定义金子结构体，包含质量、价值和密度
struct Gold {
	double mass;      // 每堆金子的总重量
	double value;     // 每堆金子的总价值
	double density;   // 单位重量的价值（价值密度）
};

// 比较函数，按密度从大到小排序
bool cmp(Gold& a, Gold& b) {
	return a.density > b.density;  // 返回true表示a排在b前面
}

int main(void) {
	// 加速输入输出流
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, T;  // N: 金子堆数, T: 背包承重
	cin >> N >> T;

	// 动态分配数组存储金子信息
	Gold* gold = new Gold[N];

	// 读取每堆金子的重量和价值，并计算密度
	for (int i = 0; i < N; i++) {
		cin >> gold[i].mass >> gold[i].value;
		// 计算单位价值：总价值 ÷ 总重量
		gold[i].density = gold[i].value / gold[i].mass;
	}

	// 关键步骤：按密度从大到小排序
	// 贪心策略：优先选择单位价值最高的金子
	sort(gold, gold + N, cmp);

	double summass = 0;    // 已装入背包的金子总重量
	double summoney = 0;   // 已装入背包的金子总价值

	// 贪心选择过程
	for (int i = 0; i < N; i++) {
		// 如果背包还有剩余容量
		if (summass < T) {
			double mass;  // 本次准备拿走的重量

			// 判断当前这堆金子能否全部拿走
			if (gold[i].mass < T - summass) {
				// 可以全部拿走
				mass = gold[i].mass;
			} else {
				// 只能拿走背包剩余容量的部分
				mass = T - summass;
			}

			// 计算拿走部分的价值：重量 × 单位价值
			summoney += mass * gold[i].density;
			// 更新已装重量
			summass += mass;
		} else {
			// 背包已满，提前结束循环
			break;
		}
	}

	// 输出结果，保留两位小数
	cout << fixed << setprecision(2) << summoney << endl;

	// 释放动态分配的内存
	delete[] gold;
	return 0;
}