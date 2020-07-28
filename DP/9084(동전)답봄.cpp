#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

int t, n, m, dong[21],dp[10001];

int main() {
	scanf("%d", &t);
	while (t--) {
		dp[0]=1;
		scanf("%d", &n);
		for (int i=0;i<n;i++) {
			scanf("%d", &dong[i]);
		}
		scanf("%d", &m);
		for (int i=0;i<n;i++) {
			for (int j=dong[i];j<=m;j++) {
				if (j-dong[i]>=0) {
					dp[j]+=dp[j-dong[i]];
				} 
			}
		}
		printf("%d\n", dp[m]);
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}