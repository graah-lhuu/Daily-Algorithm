#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct Dot {
	int x;
	int y;
	int z;
};

bool cmp(Dot &a, Dot &b) {
	return a.z < b.z;
}

int main(void) {
	int n;
	cin >> n;

	Dot* dot = new Dot[n];

	for (int i = 0; i < n; i++) {
		cin >> dot[i].x >> dot[i].y >> dot[i].z;
	}

	sort(dot, dot + n, cmp);

	double dis;
	dis = 0;

	for (int i = 0; i < n - 1; i++) {
		dis += sqrt(
			pow(dot[i].x - dot[i + 1].x, 2) 
			+ pow(dot[i].y - dot[i + 1].y, 2) 
			+ pow(dot[i].z - dot[i + 1].z, 2)
		);
	}

	cout << fixed << setprecision(3) << dis << endl;
	delete[] dot;
	return 0;
}