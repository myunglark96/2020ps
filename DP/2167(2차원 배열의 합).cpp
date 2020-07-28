#include <iostream>
using namespace std;

int n, m, sx, sy, ex, ey, k,arr[303][303],sum;

int main() {
	scanf_s("%d%d", &n, &m);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}
	scanf_s("%d", &k);
	while (k--){
		scanf_s("%d%d%d%d", &sy, &sx, &ey, &ex);
		for (int i=sy;i<=ey;i++) {
			for (int j=sx;j<=ex;j++) {
				sum=sum+arr[i][j];
			}
		}
		printf("%d\n", sum);
		sum=0;
	}
		
	return 0;
}