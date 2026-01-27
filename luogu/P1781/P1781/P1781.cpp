#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Man {
	int id;
	string vote;
};

bool cmp(Man& a, Man& b) {
	if (a.vote.length() != b.vote.length()) return a.vote.length() > b.vote.length();
	return a.vote > b.vote;
}

int main(void) {
	int n;
	cin >> n;
	Man* man = new Man[n];
	for (int i = 0; i < n; i++) {
		man[i].id = i + 1;
		cin >> man[i].vote;
	}

	sort(man, man + n, cmp);
	cout << man[0].id << endl;
	cout << man[0].vote << endl;


	delete[] man;
	return 0;
}