#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int dp[1010],n;

int main() {
	scanf("%d", &n);
	dp[1]=1, dp[2]=3;
	for (int i=3;i<=n;i++) {
		dp[i]=(dp[i-1]+dp[i-2]*2)%10007;
	}
	printf("%d", dp[n]);
	return 0;
}