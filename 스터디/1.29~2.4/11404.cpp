#include <iostream>
#include <algorithm>
using namespace std;

int d[105][105];
int p[105][105];

int main() {
	int n,m, u,v,w;
	scanf_s("%d%d", &n, &m);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (i==j) d[i][j]=0;
			else d[i][j]=987654321;
		}
	}
	for (int i=0; i<m; i++) {
		scanf_s("%d%d%d", &u, &v, &w);
		d[u][v]=min(d[u][v],w);
	}

	for (int k=1; k<=n; k++) {
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if (d[i][k]+d[k][j]<d[i][j]) {
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (d[i][j]==987654321) printf("0 ");
			else printf("%d ", d[i][j]);
		}
		printf("\n");
	}
	return 0;
}