#include <iostream>
using namespace std;

int main() {
	int n, w[50], h[50], count[50]={ 0, };
	scanf_s("%d", &n);
	for (int i=0; i<n; i++) {
		scanf_s("%d%d", &w[i], &h[i]);
	}

	for (int i=0; i<n; i++) {
		for (int j=0;j<n;j++) {
			if (w[i]<w[j]&&h[i]<h[j]) count[i]++;
		}
	}

	for (int i=0; i<n; i++) {
		printf("%d ", count[i]+1);
	}
	return 0;
}