#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long dp[101];

int main() {
	int t, n;
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	dp[4]=2;
	dp[5]=2;
	for (int i=6;i<=100;i++) {
		dp[i]=dp[i-1]+dp[i-5];
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		cout<<dp[n]<<"\n";
	}
	return 0;
}

