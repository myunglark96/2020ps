#include <iostream>
#include <algorithm>
using namespace std;

int n, m, u, v, w, adj[505][505], dist[505];

int main() {
	bool ansminus=false;
	scanf_s("%d%d", &n, &m);
	for (int i=1;i<=n;i++) {
		dist[i]=987654321;
		for (int j=1; j<=n; j++) {
			adj[i][j]=987654321;
		}
	}
	for (int i=0; i<m;i++) {
		scanf_s("%d%d%d", &u, &v, &w);
		if (adj[u][v]!=987654231) adj[u][v]=min(adj[u][v], w);
		else adj[u][v]=w;
	}
	adj[1][1]=0;
	dist[1]=0;
	for (int cy=0; cy<n; cy++) {
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if (i!=j&&adj[i][j]!=987654321&&dist[i]!=987654321) {
					if (dist[j]>dist[i]+adj[i][j]) { 
						dist[j]=dist[i]+adj[i][j];
						if (cy==n-1) ansminus=true;
					}
				}
			}
		}
	}
	if (ansminus) {
		printf("-1\n");
	}
	else {
		for (int i=2; i<=n; i++) {
			if (dist[i]==987654321) printf("-1\n");
			else printf("%d\n", dist[i]);
		}
	}
	return 0;
}