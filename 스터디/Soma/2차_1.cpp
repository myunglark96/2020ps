#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int n,arr[101010],dp[101010],ans;

int main() {
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &arr[i]);
		dp[i]=arr[i];
	}
	for (int i=1;i<n;i++) {
		dp[i]=max(dp[i], dp[i-1]+arr[i]);
	}
	
	for (int i=0;i<n;i++) {
		if (ans<dp[i]) ans=dp[i];
	}
	cout<<ans;
	return 0;
}