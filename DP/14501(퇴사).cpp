#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int n,t[20],p[20],dp[100];

int main() {
	scanf("%d", &n);
	for (int i=1;i<=n;i++) {
		scanf("%d%d", &t[i], &p[i]);
	}
	for (int i=1;i<=n;i++) {
		dp[i+t[i]-1]=max(dp[i+t[i]-1], dp[i-1]+p[i]);
		dp[i]=max(dp[i], dp[i-1]);
	}
	cout<<dp[n];
	return 0;
}