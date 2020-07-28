#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int n,dp[1010][10],sum;

int main() {
	scanf("%d", &n);
	for (int i=1;i<=n;i++) {
		for (int j=0;j<10;j++) {
			if (i==1) dp[i][j]=1;
			for (int k=0;k<10;k++) {
				if (k<=j) dp[i][j]=(dp[i][j]+dp[i-1][k])%10007;
			}
		}
	}
	for (int i=0;i<10;i++) sum=(sum+dp[n][i])%10007;
	printf("%d", sum);
	return 0;
}