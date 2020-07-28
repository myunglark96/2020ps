#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int t, tri[501][501],dp[501][501],maxdp;

int main() {
	scanf("%d", &t);
	for (int i=1;i<=t;i++) {
		for (int j=1;j<=i;j++) {
			scanf("%d", &tri[i][j]);
		}
	}

	for (int i=1;i<=t;i++) {
		for (int j=1;j<=i;j++) {
			if (j==1) dp[i][j]=dp[i-1][j]+tri[i][j];
			else if (j==i) dp[i][j]=dp[i-1][j-1]+tri[i][j];
			else dp[i][j]=max(dp[i-1][j-1], dp[i-1][j])+tri[i][j];
		}
	}
	for (int i=1;i<=t;i++) maxdp=max(maxdp, dp[t][i]);
	cout<<maxdp;
	return 0;
}