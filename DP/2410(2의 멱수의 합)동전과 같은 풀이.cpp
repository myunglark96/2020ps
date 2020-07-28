#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

long long dp[1000001];

int main() {
	int n;
	dp[0]=1;
	scanf("%d", &n);
	for (int j=1;j<=n;j=j*2) {
		for (int i=j;i<=n;i++) {
			dp[i]=(dp[i]+dp[i-j])%1000000000;
		}
	}
	cout<<dp[n];
	return 0;
}