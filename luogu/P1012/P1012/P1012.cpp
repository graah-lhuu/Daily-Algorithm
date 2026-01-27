#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Num {
	string value;
};

bool cmp(Num& a, Num& b) {
	return (a.value + b.value) >= (b.value + a.value);

}

int main(void) {
	int n;
	cin >> n;
	Num* num = new Num[n];
	
	for (int i = 0; i < n; i++) {
		cin >> num[i].value;
	}

	sort(num, num + n, cmp);
	
	for (int i = 0; i < n; i++) {
		cout << num[i].value;
	}
	delete[] num;
	return 0;
}