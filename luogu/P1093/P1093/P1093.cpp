#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
	int id;
	int chinese;
	int math;
	int english;
	int total;
};

bool cmp(const Student& a, const Student& b) {
	if (a.total != b.total) return a.total > b.total;
	if (a.chinese != b.chinese) return a.chinese > b.chinese;
	return a.id < b.id;
}

int main(void) {
	int n;
	cin >> n;
	Student* stu = new Student[n];//动态分配内存

	for (int i = 0; i < n; i++) {
		stu[i].id = i + 1;
		cin >> stu[i].chinese >> stu[i].math >> stu[i].english;
		stu[i].total = stu[i].chinese + stu[i].math + stu[i].english;
	}//输入模块

	sort(stu, stu + n, cmp);

	for (int i = 0; i < 5; i++) {
		cout << stu[i].id << " " << stu[i].total << endl;
	}

	delete[] stu;
	return 0;
}