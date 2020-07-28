#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int n, dp[31];

int main() {
	scanf("%d", &n);
	dp[2]=3;
	for (int i=4;i<=n;i++) {
		dp[i]=dp[i-2]*3+2;
		for (int j=2;j<=i-4;j+=2) {
			dp[i]+=dp[j]*2;
		}
	}

	for (int i=3;i<=n;i+=2) dp[i]=0;
	if (n==0) cout<<1;
	else cout<<dp[n];
	return 0;
}