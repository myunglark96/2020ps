#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int n,arr[1010],dp[1010],maxnum;

int main() {
	scanf("%d", &n);
	for (int i=0;i<n;i++) {
		scanf("%d", &arr[i]);
		dp[i]=1;
	}
	
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			if (arr[i]<arr[j]) dp[j]=max(dp[j],dp[i]+1);
		}
	}
	for (int i=0;i<n;i++) {
		if (maxnum<dp[i]) maxnum=dp[i];
	}
	cout<<maxnum;
	return 0;
}