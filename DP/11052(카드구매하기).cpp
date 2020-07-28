#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[10101],dp[10101];

int main() {
	scanf("%d", &n);
	for (int i=1;i<=n;i++) {
		scanf("%d", &arr[i]);
		dp[i]=arr[i];
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			if (j>i) dp[j]=max(dp[j], dp[j-i]+arr[i]);
		}
	}
	cout<<dp[n];
	return 0;
}