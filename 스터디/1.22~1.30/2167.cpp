#include <iostream>
using namespace std;

int map[300][300];

int main() {
	int n, m, k, startx, starty, endx, endy, ans=0;
	scanf_s("%d%d", &n, &m);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			scanf_s("%d", &map[i][j]);
		}
	}
	scanf_s("%d", &k);
	for (int i=0; i<k; i++) {
		scanf_s("%d%d%d%d", &starty, &startx, &endy, &endx);
		for (int j=starty-1; j<=endy-1; j++) {
			for (int l=startx-1; l<=endx-1; l++) {
				ans=ans+map[j][l];
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}