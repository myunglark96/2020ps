#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1010], dp[1010],ans;

int main() {
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &arr[i]);
		dp[i]=arr[i];
	}

	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			if (arr[i]<arr[j]) dp[j]=max(dp[j],dp[i]+arr[j]);
		}
	}

	for (int i=0;i<n;i++) {
		if (ans<dp[i]) ans=dp[i];
	}
	cout<<ans;
	return 0;
}