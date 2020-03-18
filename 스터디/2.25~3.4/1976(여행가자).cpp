#include <iostream>
using namespace std;

int cities[205][205],n,m,trip[1010];

int main() {
	scanf_s("%d%d", &n, &m);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			scanf_s("%d", &cities[i][j]); 
		}
	}

	for (int i=1; i<=n; i++) cities[i][i]=1;

	for (int i=0; i<m; i++) {
		scanf_s("%d", &trip[i]);
	}

	for (int k=1; k<=n; k++) {
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if (cities[i][j]==0&&(cities[i][k]==1&&cities[k][j])) {
					cities[i][j]=1;
				}
			}
		}
	}

	bool ans=true;
	for (int i=1; i<m; i++) {
		if (cities[trip[i-1]][trip[i]]==0) ans=false;
	}

	if (ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}

