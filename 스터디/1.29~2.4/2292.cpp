#include <iostream>
using namespace std;

long long n, ans;

void searchnum(long long comp, int depth) {
	if (n<=comp) {
		ans=depth;
		return;
	}
	return searchnum(comp+6*depth, depth+1);
}

int main() {
	scanf_s("%ld", &n);
	searchnum(1, 1);
	printf("%ld", ans);
	return 0;
}