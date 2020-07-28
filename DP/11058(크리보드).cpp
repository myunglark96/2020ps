#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long dp[101], ans[101];

int main() {
	scanf("%d", &n);
	for (int i=1;i<=100;i++) {
		ans[i]=i;
	}

	for (int i=1;i<=97;i++) {
		dp[i+3]=ans[i]*2;
		ans[i+3]=max(ans[i+3], ans[i]*2);
		for (int j=i+4;j<=100;j++) {
			dp[j]=dp[j-1]+ans[i];
			ans[j]=max(ans[j], dp[j]);
		}
	}

	cout<<ans[n];
	return 0;
}