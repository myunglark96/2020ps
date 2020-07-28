#include <iostream>
using namespace std;

int ans[100000];

int hs(int i, int n) {
	if (n==1) return 1;
	if (n%2==0) {
		return hs(i, n/2);
	}
	else {
		if (ans[i]<n*3+1) ans[i]=n*3+1;
		return hs(i, n*3+1);
	}
}

int main() {
	int t,n;
	scanf_s("%d", &t);
	for (int i=0;i<t;i++) {
		scanf_s("%d", &n);
		ans[i]=n;
		hs(i, n);
	}

	for (int i=0;i<t;i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}