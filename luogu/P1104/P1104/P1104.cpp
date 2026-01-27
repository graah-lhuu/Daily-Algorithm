#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Person {
	int id;
	string name;
	int year;
	int month;
	int day;
};

bool cmp(Person &a, Person &b) {
	if (a.year != b.year) return a.year < b.year;
	if (a.month != b.month) return a.month < b.month;
	if (a.day != b.day) return a.day < b.day;
	return a.id > b.id;

}

int main(void) {
	int n;
	cin >> n;
	Person* p = new Person[n];

	for (int i = 0; i < n; i++) {
		p[i].id = i;
		cin >> p[i].name >> p[i].year >> p[i].month >> p[i].day; 
	}

	sort(p, p + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << p[i].name/* << " " << p[i].year << " " << p[i].month << " " << p[i].day */<< endl;
	}

	delete[] p;
	return 0;

}