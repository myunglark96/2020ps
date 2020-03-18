#include <iostream>
#include <algorithm>
using namespace std;

int t,n, a[101], b[101];

void swap(int* arr) {
	int tmp;
	tmp=arr[0];
	for (int i=0;i<n-1;i++) {
		arr[i]=arr[i+1];
	}
	arr[n-1]=tmp;
	return;
}

int main() {
	scanf_s("%d", &t);
	for (int i=0;i<t;i++) {
		scanf("%d", &n);
		for (int k=0;k<n;k++) {
			scanf("%d", &a[k]);
		}
		for (int l=0;l<n;l++) {
			scanf("%d", &b[l]);
		}

		sort(a, a+n);
		sort(b, b+n);

		for (int j=0;j<n;j++) {
			printf("%d ", a[j]);
		}
		printf("\n");
		for (int j=0;j<n;j++) {
			printf("%d ", b[j]);
		}
		printf("\n");
	}
	return 0;
}