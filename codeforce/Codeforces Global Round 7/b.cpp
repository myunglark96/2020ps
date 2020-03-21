#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[200001], b[200001], a[200001], am;

int main() {
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &b[i]);
	}
	for (int i=0;i<n;i++) {
		if (i==0) {
			a[0]=b[0];
		}
		else if (i==1) {
			a[1]=b[1]+a[0];
			am=max(a[1], a[0]);
		}
		else {
			am=max(am, a[i-1]);
			a[i]=b[i]+am;
		}
	}
	for (int i=0;i<n;i++) {
		printf("%d ",a[i]);
	}
	return 0;
}