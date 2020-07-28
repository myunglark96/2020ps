#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int t, n, m,dp[33][33],fect[33];

int fecto(int n) {
	if (fect[n]!=0) return fect[n];
	if (n==1||n==0) return 1;
	else {
		fect[n]=fecto(n-1)*n;
		return fect[n];
	} 
}

int main() {
	for (int i=1;i<=30;i++) {
		for (int j=i;j<=30;j++) {
			if (i==1) dp[i][j]=j;
			else {
				for (int k=1;k<=j-i+1;k++) {
					dp[i][j]+=dp[i-1][j-k];
				}
			}
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		printf("%d\n", dp[n][m]);
	}
	return 0;
}