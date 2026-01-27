#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Man {
	int id;
	int score;
};

bool cmp(Man& a,Man& b) {
	if (a.score != b.score) return a.score > b.score;
	return a.id < b.id;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	Man* man = new Man[n];

	for (int i = 0; i < n; i++) {
		cin >> man[i].id >> man[i].score;
	}

	sort(man, man + n, cmp);

	int count = (int)floor(m * 1.5);
	
	while (man[count - 1].score == man[count].score) {
		count++;
	}

	cout << man[count-1].score << " " << count << endl;
	for (int i = 0; i < count; i++) {
		cout << man[i].id << " " << man[i].score << endl;
	}

	delete[] man;

	return 0;
}