#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int n,tmp,ans,dp[100001];

int main() {
	scanf("%d", &n);
	for (int i=1;i<=n;i++) {
		dp[i]=i;
	}

	for (int j=1;j<318;j++) {
		for (int i=j*j;i<=n;i++){
			dp[i]=min(dp[i], dp[i-j*j]+1);
		}
	}
	cout<<dp[n];
	return 0;
}