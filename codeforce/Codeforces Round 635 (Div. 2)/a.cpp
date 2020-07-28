#include <iostream>
using namespace std;

int t, a, b, c, d;

int main() {
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d%d%d%d", &a, &b, &c, &d);
		printf("%d %d %d\n", b, c, c);
	}
	return 0;
}