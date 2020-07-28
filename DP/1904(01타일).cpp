#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[1000001];

int main() {
	scanf("%d", &n);
	dp[1]=1;
	dp[2]=2;
	for (int i=3;i<=n;i++) {
		dp[i]=(dp[i-1]+dp[i-2])%15746;
	}
	cout<<dp[n];
	return 0;
}